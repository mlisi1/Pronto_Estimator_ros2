#ifndef PRONTO_CONTROLLER_HPP
#define PRONTO_CONTROLLER_HPP
#include "rclcpp/qos.hpp"
#include "rclcpp/subscription.hpp"
#include "rclcpp/rclcpp.hpp"
#include "controller_interface/controller_interface.hpp"
#include "controller_interface/helpers.hpp"
#include "hardware_interface/loaned_command_interface.hpp"
#include "hardware_interface/loaned_state_interface.hpp"
#include "hardware_interface/types/hardware_interface_type_values.hpp"
#include "pronto_ros2_controller/proprioceptive_sensor_manager.hpp"

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

#include "tf2_ros/transform_broadcaster.h"

#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <geometry_msgs/msg/twist_with_covariance_stamped.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Vector3.h>

#include "pronto_core/sensing_module.hpp"
#include "pronto_core/state_est.hpp"
#include "pronto_core/rotations.hpp"

#include <array>

#define COV_PAR_NUM 7
#define STT_PAR_NUM 4
#define PRONTO_NAMES 5
#define PUB_SET_UP 4
#define HISTORY 1
namespace pronto_controller
{
    using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;
    using StateEst = pronto::StateEstimator;
    using Pose_with_Cov_msg = geometry_msgs::msg::PoseWithCovarianceStamped;
    using Twist_with_Cov_msg = geometry_msgs::msg::TwistWithCovarianceStamped;
    class Pronto_Controller : public controller_interface::ControllerInterface
    {
        public:
            Pronto_Controller();
           ~Pronto_Controller();
            CallbackReturn on_init() override;

            controller_interface::InterfaceConfiguration command_interface_configuration() const override;

            controller_interface::InterfaceConfiguration state_interface_configuration() const override;

            CallbackReturn on_configure(const rclcpp_lifecycle::State & previous_state) override;

            CallbackReturn on_activate(const rclcpp_lifecycle::State & previous_state) override; 

            CallbackReturn on_deactivate(const rclcpp_lifecycle::State & previous_state) override;

            CallbackReturn on_cleanup(const rclcpp_lifecycle::State & previous_state) override;

            controller_interface::return_type update(
                const rclcpp::Time & time, const rclcpp::Duration & period
            ) override;
        protected:
            bool initializeFilter();

            void initializeState();

            void initializeCovariance();

            bool isFilterInitialized()
            {
                return filter_initialized_;
            };
            
            bool isExteroceptiveSensorInit()
            {
                // TODO call the class for exteroceptive sensor 
                // when will be used it will be called
                return true;
            }
        private:
            //state estimator
            std::shared_ptr<StateEst> stt_est_;

            pronto::RBIS default_state_, init_state_,head_state_;
            pronto::RBIM default_cov_,init_cov_,head_cov_;

            rclcpp::Publisher<Twist_with_Cov_msg>::SharedPtr twist_pub_;
            rclcpp::Publisher<Pose_with_Cov_msg>::SharedPtr pose_pub_;



            

            // state estimator shared ptr
            // proprioceptive sensor shared ptr
            std::vector<std::string> est_params_ = {
                "sigma0/vb",
                "sigma0/chi_xy",
                "sigma0/chi_x",
                "sigma0/Delta_xy",
                "sigma0/Delta_z",
                "sigma0/gyro_bias",
                "sigma0/acc_bias",
                "x0/velocity",
                "x0/angular_velocity",
                "x0/position",
                "x0/rpy",
            };
            std::vector<std::string> output_params_ = {
                "pose_topic",
                "pose_frame_id",
                "twist_topic",
                "twist_frame_id",
                "tf_child_frame_id",

                "publish_pose",
                "publish_twist",
                "republish_sensors",

               

            };
            

            std::array<bool,3> pub_data_ = {false,false,false};

            uint64_t history_span_;

            tf2::Vector3 temp_v3_;
            tf2::Quaternion temp_q_;

            bool filter_initialized_ = false;

            Twist_with_Cov_msg twist_msg_;
            Pose_with_Cov_msg pose_msg_;
            geometry_msgs::msg::TransformStamped transform_msg_;

            std::shared_ptr<tf2_ros::TransformBroadcaster> tf2_broadcaster_;

            

    };
};
#endif