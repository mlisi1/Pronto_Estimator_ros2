#pragma once

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include <cstdlib>
#include <cxxabi.h>


#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Vector3.h>

#include "nav_msgs/msg/path.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"
#include "geometry_msgs/msg/twist_with_covariance_stamped.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"


#include <pronto_core/sensing_module.hpp>
#include <pronto_core/state_est.hpp>
#include <pronto_core/rotations.hpp>

// #include "pronto_ros2/ins_ros_handler.hpp"



using SensorId_t = std::string;

namespace pronto {

template<typename T>
std::string type_name()
{
    int status;
    std::string tname = typeid(T).name();
    char *demangled_name = abi::__cxa_demangle(tname.c_str(), nullptr, nullptr, &status);
    if (status == 0) {
        tname = demangled_name;
        std::free(demangled_name);
    }
    return tname;
}





class ProntoNode : public rclcpp::Node
{
    public:

        
        ProntoNode();

        ~ProntoNode();

		template<typename MsgT>
        void addSensingModule(pronto::SensingModule<MsgT>& module, const SensorId_t& sensor_id, bool roll_forward,bool publish_head, const std::string& topic, bool subscribe = true) ;
		
		template<typename MsgT>
        void addInitModule(pronto::SensingModule<MsgT>& module, const SensorId_t& sensor_id, const std::string& topic, bool subscribe = true);

        bool areModulesInitialized();

        bool isFilterInitialized();

        inline void getState(pronto::RBIS& state, pronto::RBIM& cov) const;

        inline bool reset(const pronto::RBIS& state, const pronto::RBIM& cov);

		template<class MsgT>
        void initCallback(const MsgT & msg, const SensorId_t& Key);

		template<class MsgT>
        void callback(const MsgT & msg, const SensorId_t& sensor_id);


    protected:

        bool initializeFilter() ;

        void initializeState() ;

        void initializeCovariance();


    public:
		EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	private:
		
		std::shared_ptr<StateEstimator> state_est_;
		std::map<SensorId_t, rclcpp::SubscriptionBase::SharedPtr> sensor_subscribers_;
		std::map<SensorId_t, rclcpp::SubscriptionBase::SharedPtr> secondary_subscribers_;
		std::map<SensorId_t, rclcpp::SubscriptionBase::SharedPtr> init_subscribers_;
		std::map<SensorId_t, void*> active_modules_;
		std::map<SensorId_t, void*> init_modules_;
		std::map<SensorId_t, bool> initialized_list_;
		std::map<SensorId_t, bool> roll_forward_;
		std::map<SensorId_t, bool> publish_head_;

		pronto::RBIS default_state;
		pronto::RBIM default_cov;

		pronto::RBIS init_state;
		pronto::RBIM init_cov;

		pronto::RBIS head_state;
		pronto::RBIM head_cov;
		

		rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr pose_pub_;
		rclcpp::Publisher<geometry_msgs::msg::TwistWithCovarianceStamped>::SharedPtr twist_pub_;
		rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr aicp_path_publisher;
		std::shared_ptr<tf2_ros::TransformBroadcaster> tf2_broadcaster_;
		geometry_msgs::msg::TransformStamped transform_msg_;
		bool publish_tf_ = false;

		geometry_msgs::msg::PoseWithCovarianceStamped pose_msg_;
		geometry_msgs::msg::TwistWithCovarianceStamped twist_msg_;

		nav_msgs::msg::Path aicp_path;
		

		uint64_t history_span_;

		tf2::Vector3 temp_v3;
		tf2::Quaternion temp_q;

		bool filter_initialized_ = false;
		bool verbose_ = false;


};


#include "pronto_ros2/pronto_ros2_node.inl"

}