// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pronto_msgs:msg/BipedForceTorqueSensors.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__BIPED_FORCE_TORQUE_SENSORS__BUILDER_HPP_
#define PRONTO_MSGS__MSG__DETAIL__BIPED_FORCE_TORQUE_SENSORS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pronto_msgs/msg/detail/biped_force_torque_sensors__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pronto_msgs
{

namespace msg
{

namespace builder
{

class Init_BipedForceTorqueSensors_r_hand
{
public:
  explicit Init_BipedForceTorqueSensors_r_hand(::pronto_msgs::msg::BipedForceTorqueSensors & msg)
  : msg_(msg)
  {}
  ::pronto_msgs::msg::BipedForceTorqueSensors r_hand(::pronto_msgs::msg::BipedForceTorqueSensors::_r_hand_type arg)
  {
    msg_.r_hand = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pronto_msgs::msg::BipedForceTorqueSensors msg_;
};

class Init_BipedForceTorqueSensors_l_hand
{
public:
  explicit Init_BipedForceTorqueSensors_l_hand(::pronto_msgs::msg::BipedForceTorqueSensors & msg)
  : msg_(msg)
  {}
  Init_BipedForceTorqueSensors_r_hand l_hand(::pronto_msgs::msg::BipedForceTorqueSensors::_l_hand_type arg)
  {
    msg_.l_hand = std::move(arg);
    return Init_BipedForceTorqueSensors_r_hand(msg_);
  }

private:
  ::pronto_msgs::msg::BipedForceTorqueSensors msg_;
};

class Init_BipedForceTorqueSensors_r_foot
{
public:
  explicit Init_BipedForceTorqueSensors_r_foot(::pronto_msgs::msg::BipedForceTorqueSensors & msg)
  : msg_(msg)
  {}
  Init_BipedForceTorqueSensors_l_hand r_foot(::pronto_msgs::msg::BipedForceTorqueSensors::_r_foot_type arg)
  {
    msg_.r_foot = std::move(arg);
    return Init_BipedForceTorqueSensors_l_hand(msg_);
  }

private:
  ::pronto_msgs::msg::BipedForceTorqueSensors msg_;
};

class Init_BipedForceTorqueSensors_l_foot
{
public:
  explicit Init_BipedForceTorqueSensors_l_foot(::pronto_msgs::msg::BipedForceTorqueSensors & msg)
  : msg_(msg)
  {}
  Init_BipedForceTorqueSensors_r_foot l_foot(::pronto_msgs::msg::BipedForceTorqueSensors::_l_foot_type arg)
  {
    msg_.l_foot = std::move(arg);
    return Init_BipedForceTorqueSensors_r_foot(msg_);
  }

private:
  ::pronto_msgs::msg::BipedForceTorqueSensors msg_;
};

class Init_BipedForceTorqueSensors_header
{
public:
  Init_BipedForceTorqueSensors_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BipedForceTorqueSensors_l_foot header(::pronto_msgs::msg::BipedForceTorqueSensors::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BipedForceTorqueSensors_l_foot(msg_);
  }

private:
  ::pronto_msgs::msg::BipedForceTorqueSensors msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pronto_msgs::msg::BipedForceTorqueSensors>()
{
  return pronto_msgs::msg::builder::Init_BipedForceTorqueSensors_header();
}

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__BIPED_FORCE_TORQUE_SENSORS__BUILDER_HPP_
