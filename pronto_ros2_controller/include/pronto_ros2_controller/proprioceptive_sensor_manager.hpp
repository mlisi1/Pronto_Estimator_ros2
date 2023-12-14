#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

#include "pronto_core/ins_module.hpp"
#include <vector>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "pronto_ros2_controller/legodom_manager.hpp"



namespace pronto_controller
{
    
    using INS_module = pronto::InsModule;
    using StateEst = pronto::StateEstimator;
    class Prop_Sensor_Manager
    {
        public:
            Prop_Sensor_Manager(
                rclcpp_lifecycle::LifecycleNode::SharedPtr controller,
                std::map<std::string , std::tuple<double,double,double>> joints_map,
                std::string urdf_path):
            filt_controler_(controller)
            {
                legodom_man_ = std::make_unique<LegOdom_Manager>(controller,joints_map,urdf_path);
            };
            
            ~Prop_Sensor_Manager(){};
            
            pronto::RBISUpdateInterface* update_odom(rclcpp::Time time, pronto::StateEstimator* stt_est);
            
            void conf_prop_sens()
            {
                // configure ins sensor
                conf_ins();
                //configure proprioceptive odometry
                legodom_man_->get_stance_param();
                legodom_man_->get_odom_param();
            }
            
            // function to set the time duration of the update
            void setInsTimeStep(rclcpp::Duration dur)
            {
                ins_->setTimeStep(dur.seconds());
            };
            // this function use the Ins_module to process the incoming data and update the filter state and covariance
            pronto::RBISUpdateInterface* processInsData(
                    const pronto::ImuMeasurement * msr,
                    StateEst * est
            );
            
            // this function use the Ins_module to initialize the filter
            bool isInsInitialized(
                const pronto::ImuMeasurement * msr,
                std::map<std::string,bool> init_map,
                const pronto::RBIS& default_stt,
                const pronto::RBIM& default_cov,
                pronto::RBIS& init_stt,
                pronto::RBIM& init_cov
                );
            bool get_ins_roll_forward()
            {
                return roll_forward_on_receive_;
            }
        protected:
            void conf_ins();
        private:
            // init INS part 
            
            // shared pointer to the pronto core ins module, TODO check the correct initialization of it
            std::unique_ptr<INS_module> ins_;

            int downsample_factor_,utime_offset_;

            bool roll_forward_on_receive_;

            rclcpp_lifecycle::LifecycleNode::SharedPtr filt_controler_;

            std::unique_ptr<LegOdom_Manager> legodom_man_;
    };
           
};