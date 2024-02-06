#include "rclcpp/rclcpp.hpp"
#include "rclcpp/qos.hpp"
#include "rclcpp/subscription.hpp"
#include "rclcpp/publisher.hpp"
#include "pronto_tuning/spline.h"
#include <vector>
#include <array>
#include <string>
#include <cmath>
#include <iostream>
#include <cassert>
#include "velocity_command_msgs/msg/simple_velocity_command.hpp"

using CmdMsg = velocity_command_msgs::msg::SimpleVelocityCommand;
namespace command_node
{
    class CommandNode : public rclcpp::Node
    {
        public:
            CommandNode():
            Node("command_node")
            {
                std::cerr<<"pass here"<<std::endl;
                this->declare_parameter("topic_name",std::string());
                this->declare_parameter("timer_period_ms",10);
                period_ = get_parameter("timer_period_ms").as_int();
                topic_name_ = this->get_parameter("topic_name").as_string();
                this->declare_parameter("set_point_list",std::vector<std::string>());
                if(!this->get_parameter("set_point_list",spline_list_))
                {
                    RCLCPP_ERROR(get_logger(), "Error during the parsing of spline list");
                    throw(std::logic_error("yaml file error"));
                }
                if(spline_list_.empty())
                {
                    RCLCPP_ERROR(get_logger(), "Spline list can not be empty");
                    throw(std::logic_error(""));
                }
                for(auto &spline:spline_list_)
                {
                    
                    this->declare_parameter(spline + ".vx",std::nan(""));
                    this->declare_parameter(spline + ".vy",std::nan(""));
                    this->declare_parameter(spline + ".omega",std::nan(""));
                    this->declare_parameter(spline + ".time",std::nan(""));
                }
                spline_vx_list_.resize(spline_list_.size());
                spline_vy_list_.resize(spline_list_.size());
                spline_om_list_.resize(spline_list_.size());
                spline_time_list_.resize(spline_list_.size());
                for(size_t i = 0; i < spline_list_.size(); i++)
                {
                    spline_vx_list_[i] = get_parameter(spline_list_[i] + ".vx").as_double();
                    spline_vy_list_[i] = get_parameter(spline_list_[i] + ".vy").as_double();
                    spline_om_list_[i] = get_parameter(spline_list_[i] + ".omega").as_double();
                    spline_time_list_[i] = get_parameter(spline_list_[i] + ".time").as_double();
                    if( spline_vx_list_[i] == std::nan("") || 
                        spline_vy_list_[i] == std::nan("") ||
                        spline_om_list_[i] == std::nan("") ||
                        spline_time_list_[i] == std::nan(""))
                    {
                        RCLCPP_ERROR(get_logger(), "Error during the spline param parsing at index %ld",i);
                        assert(true);
                    }
                    RCLCPP_INFO(get_logger(),"the param of spline %ld are %f,%f,%f,%f", i, spline_vx_list_[i], spline_vy_list_[i], spline_om_list_[i], spline_time_list_[i]);
                    if(i!= 0)
                    {
                        if(spline_time_list_[i] <= spline_time_list_[i-1])
                        {
                            RCLCPP_ERROR(get_logger(), "The Time must be monotonic, time param error at index at index %ld",i);
                            assert(true);
                        }
                    }
                }
                // 
                vx_spline_.set_boundary(tk::spline::first_deriv,0.0,tk::spline::first_deriv,0.0);
                vx_spline_.set_points(spline_time_list_,spline_vx_list_,tk::spline::linear);
                vy_spline_.set_boundary(tk::spline::first_deriv,0.0,tk::spline::first_deriv,0.0);
                vy_spline_.set_points(spline_time_list_,spline_vy_list_,tk::spline::linear);
                om_spline_.set_boundary(tk::spline::first_deriv,0.0,tk::spline::first_deriv,0.0);
                om_spline_.set_points(spline_time_list_,spline_om_list_,tk::spline::linear);
                
                // vx_spline_ = std::make_unique<tk::spline>(spline_vx_list_,spline_time_list_,tk::spline::cspline);
                // vx_spline_(spline_time_list_,spline_vx_list_,tk::spline::cspline_hermite,false,tk::spline::first_deriv,0.0,tk::spline::first_deriv,0.0);
                // vy_spline_ = tk::spline(spline_time_list_,spline_vx_list_,tk::spline::cspline_hermite,false,tk::spline::first_deriv,0.0,tk::spline::first_deriv,0.0);
                // om_spline_ = tk::spline(spline_time_list_,spline_vx_list_,tk::spline::cspline_hermite,false,tk::spline::first_deriv,0.0,tk::spline::first_deriv,0.0);
                pub_ = create_publisher<CmdMsg>(topic_name_,rclcpp::QoS(10));

                timer_ = create_wall_timer(std::chrono::duration<int,std::milli>(period_), std::bind(&CommandNode::timer_callback,this));

                // std::vector<double> prova = {0.0,1.0,2.0,3.0,4.0,5.0,6.0};
                // for(size_t i = 0; i < prova.size(); i++)
                // {
                //     RCLCPP_INFO(get_logger(),"the value of spline computed in %f is %f",prova[i], vx_spline_(prova[i]));
                // }
            }
        private: 
            
            void timer_callback()
            {
                rclcpp::Time time_stamp = get_clock()->now();
                double secs;
                if(offset_timer_ == 0.0)
                    offset_timer_ = time_stamp.seconds();
                
                secs = time_stamp.seconds() - offset_timer_ + spline_time_list_[0];
                
                if(secs <= spline_time_list_[spline_list_.size()-1])
                {
                    msg_.set__velocity_forward(vx_spline_(secs));
                    msg_.set__velocity_lateral(vy_spline_(secs));
                    msg_.set__yaw_rate(om_spline_(secs));
                    RCLCPP_INFO(get_logger(),"now is %f and stop at %f and ms is [%f,%f,%f]",secs,spline_time_list_[spline_list_.size()-1],msg_.velocity_forward,msg_.velocity_lateral,msg_.yaw_rate);
                    pub_->publish(msg_);
                }
                else
                {
                    timer_->cancel();
                    RCLCPP_INFO(get_logger(),"The timer has been cancelled, stop sending reference");
                }
            }

            std::vector<std::string> spline_list_;
            std::string topic_name_;
            std::vector<double> spline_vx_list_,spline_vy_list_,spline_om_list_,spline_time_list_;
            // std::unique_ptr<tk::spline> vx_spline_,vy_spline,omega_spline_;
            tk::spline vx_spline_,vy_spline_,om_spline_;
            rclcpp::TimerBase::SharedPtr timer_;
            rclcpp::Publisher<CmdMsg>::SharedPtr pub_;
            CmdMsg msg_;
            double offset_timer_ = 0.0;
            int period_;
            

    };
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<command_node::CommandNode>());
    
    rclcpp::shutdown();
    
    return 0;
}