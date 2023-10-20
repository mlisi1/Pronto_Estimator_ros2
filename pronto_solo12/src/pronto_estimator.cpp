#include <rclcpp/rclcpp.hpp>
#include "pronto_quadruped_ros/stance_estimator_ros.hpp"
#include "pronto_quadruped_ros/leg_odometer_ros.hpp"
#include "pronto_quadruped_ros/bias_lock_handler_ros.hpp"
#include "pronto_quadruped_ros/legodo_handler_ros.hpp"

#include "pronto_ros/ros_frontend.hpp"
#include "pronto_ros/ins_ros_handler.hpp"
#include "pronto_ros/pose_msg_ros_handler.hpp"

#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/algorithm/kinematics.hpp>

#include <pronto_solo12/feet_contact_forces.hpp>


using std::placeholders::_1;

using namespace pronto;
using namespace pinocchio;

const std::string urdf_file = "$(find solo_robot_description)/urdf/again/solo12.urdf";
Model robot_model;

