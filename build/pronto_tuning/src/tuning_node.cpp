#include "rclcpp/rclcpp.hpp"
#include "rclcpp/qos.hpp"
#include "rclcpp/subscription.hpp"
#include "rclcpp/publisher.hpp"
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "gazebo_msgs/msg/link_states.hpp"
#include <memory>
#define FB_LINK "solo12::base_link"


#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
namespace tuning_node
{
    using std::placeholders::_1;
    using Twist = geometry_msgs::msg::Twist;
    using Pose = geometry_msgs::msg::Pose;
    using LinkStates = gazebo_msgs::msg::LinkStates;

    class Tuning_Node : public rclcpp::Node
    {
        public:
            Tuning_Node()
            : Node("tuning_node")
            {
                pub_ = this->create_publisher<Twist>("/tuning_node/ground_truth",rclcpp::QoS(10));
                sub_ = this->create_subscription<LinkStates>("gazebo/link_states",rclcpp::QoS(10),
                std::bind(&Tuning_Node::gz_sub,this,_1));
            }
            void gz_sub(const LinkStates& msg)
            {
                bool send = false;
                Twist base_twist_msg;
                Eigen::Vector3d vel_vect;
                Eigen::Quaterniond w2b_or;
                // RCLCPP_INFO(this->get_logger(),"PASS");
                for(size_t i = 0; i< msg.name.size(); i++)
                {
                    if(msg.name[i].compare(FB_LINK)== 0 && send==false)
                    {
                        vel_vect = Eigen::Vector3d(
                            msg.twist[i].linear.x,
                            msg.twist[i].linear.y,
                            msg.twist[i].linear.z);
                        w2b_or = Eigen::Quaterniond(
                            msg.pose[i].orientation.w,
                            msg.pose[i].orientation.x,
                            msg.pose[i].orientation.y,
                            msg.pose[i].orientation.z);
                        vel_vect = w2b_or.toRotationMatrix().inverse()*vel_vect;
                        
                        base_twist_msg.linear.set__x(vel_vect(0));
                        base_twist_msg.linear.set__y(vel_vect(1));
                        base_twist_msg.linear.set__z(vel_vect(2));


                        vel_vect = Eigen::Vector3d(
                            msg.twist[i].angular.x,
                            msg.twist[i].angular.y,
                            msg.twist[i].angular.z);

                        vel_vect = w2b_or.toRotationMatrix().inverse()*vel_vect;
                        
                        base_twist_msg.angular.set__x(vel_vect(0));
                        base_twist_msg.angular.set__y(vel_vect(1));
                        base_twist_msg.angular.set__z(vel_vect(2));

                        pub_->publish(base_twist_msg);
                        send = true;
                        RCLCPP_INFO(this->get_logger(),"PASS");
                    }
                }
            }
        private:
            rclcpp::Publisher<Twist>::SharedPtr pub_;
            rclcpp::Subscription<LinkStates>::SharedPtr sub_;
    };

    

}
int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<tuning_node::Tuning_Node>());
    
    rclcpp::shutdown();
    return 0;
}