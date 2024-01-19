// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pronto_msgs:msg/QuadrupedForceTorqueSensors.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__QUADRUPED_FORCE_TORQUE_SENSORS__BUILDER_HPP_
#define PRONTO_MSGS__MSG__DETAIL__QUADRUPED_FORCE_TORQUE_SENSORS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pronto_msgs/msg/detail/quadruped_force_torque_sensors__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pronto_msgs
{

namespace msg
{

namespace builder
{

class Init_QuadrupedForceTorqueSensors_rh
{
public:
  explicit Init_QuadrupedForceTorqueSensors_rh(::pronto_msgs::msg::QuadrupedForceTorqueSensors & msg)
  : msg_(msg)
  {}
  ::pronto_msgs::msg::QuadrupedForceTorqueSensors rh(::pronto_msgs::msg::QuadrupedForceTorqueSensors::_rh_type arg)
  {
    msg_.rh = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pronto_msgs::msg::QuadrupedForceTorqueSensors msg_;
};

class Init_QuadrupedForceTorqueSensors_lh
{
public:
  explicit Init_QuadrupedForceTorqueSensors_lh(::pronto_msgs::msg::QuadrupedForceTorqueSensors & msg)
  : msg_(msg)
  {}
  Init_QuadrupedForceTorqueSensors_rh lh(::pronto_msgs::msg::QuadrupedForceTorqueSensors::_lh_type arg)
  {
    msg_.lh = std::move(arg);
    return Init_QuadrupedForceTorqueSensors_rh(msg_);
  }

private:
  ::pronto_msgs::msg::QuadrupedForceTorqueSensors msg_;
};

class Init_QuadrupedForceTorqueSensors_rf
{
public:
  explicit Init_QuadrupedForceTorqueSensors_rf(::pronto_msgs::msg::QuadrupedForceTorqueSensors & msg)
  : msg_(msg)
  {}
  Init_QuadrupedForceTorqueSensors_lh rf(::pronto_msgs::msg::QuadrupedForceTorqueSensors::_rf_type arg)
  {
    msg_.rf = std::move(arg);
    return Init_QuadrupedForceTorqueSensors_lh(msg_);
  }

private:
  ::pronto_msgs::msg::QuadrupedForceTorqueSensors msg_;
};

class Init_QuadrupedForceTorqueSensors_lf
{
public:
  explicit Init_QuadrupedForceTorqueSensors_lf(::pronto_msgs::msg::QuadrupedForceTorqueSensors & msg)
  : msg_(msg)
  {}
  Init_QuadrupedForceTorqueSensors_rf lf(::pronto_msgs::msg::QuadrupedForceTorqueSensors::_lf_type arg)
  {
    msg_.lf = std::move(arg);
    return Init_QuadrupedForceTorqueSensors_rf(msg_);
  }

private:
  ::pronto_msgs::msg::QuadrupedForceTorqueSensors msg_;
};

class Init_QuadrupedForceTorqueSensors_header
{
public:
  Init_QuadrupedForceTorqueSensors_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_QuadrupedForceTorqueSensors_lf header(::pronto_msgs::msg::QuadrupedForceTorqueSensors::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_QuadrupedForceTorqueSensors_lf(msg_);
  }

private:
  ::pronto_msgs::msg::QuadrupedForceTorqueSensors msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pronto_msgs::msg::QuadrupedForceTorqueSensors>()
{
  return pronto_msgs::msg::builder::Init_QuadrupedForceTorqueSensors_header();
}

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__QUADRUPED_FORCE_TORQUE_SENSORS__BUILDER_HPP_
