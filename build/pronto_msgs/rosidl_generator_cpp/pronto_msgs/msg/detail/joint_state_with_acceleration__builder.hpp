// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pronto_msgs:msg/JointStateWithAcceleration.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__JOINT_STATE_WITH_ACCELERATION__BUILDER_HPP_
#define PRONTO_MSGS__MSG__DETAIL__JOINT_STATE_WITH_ACCELERATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pronto_msgs/msg/detail/joint_state_with_acceleration__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pronto_msgs
{

namespace msg
{

namespace builder
{

class Init_JointStateWithAcceleration_effort
{
public:
  explicit Init_JointStateWithAcceleration_effort(::pronto_msgs::msg::JointStateWithAcceleration & msg)
  : msg_(msg)
  {}
  ::pronto_msgs::msg::JointStateWithAcceleration effort(::pronto_msgs::msg::JointStateWithAcceleration::_effort_type arg)
  {
    msg_.effort = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pronto_msgs::msg::JointStateWithAcceleration msg_;
};

class Init_JointStateWithAcceleration_acceleration
{
public:
  explicit Init_JointStateWithAcceleration_acceleration(::pronto_msgs::msg::JointStateWithAcceleration & msg)
  : msg_(msg)
  {}
  Init_JointStateWithAcceleration_effort acceleration(::pronto_msgs::msg::JointStateWithAcceleration::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_JointStateWithAcceleration_effort(msg_);
  }

private:
  ::pronto_msgs::msg::JointStateWithAcceleration msg_;
};

class Init_JointStateWithAcceleration_velocity
{
public:
  explicit Init_JointStateWithAcceleration_velocity(::pronto_msgs::msg::JointStateWithAcceleration & msg)
  : msg_(msg)
  {}
  Init_JointStateWithAcceleration_acceleration velocity(::pronto_msgs::msg::JointStateWithAcceleration::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_JointStateWithAcceleration_acceleration(msg_);
  }

private:
  ::pronto_msgs::msg::JointStateWithAcceleration msg_;
};

class Init_JointStateWithAcceleration_position
{
public:
  explicit Init_JointStateWithAcceleration_position(::pronto_msgs::msg::JointStateWithAcceleration & msg)
  : msg_(msg)
  {}
  Init_JointStateWithAcceleration_velocity position(::pronto_msgs::msg::JointStateWithAcceleration::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_JointStateWithAcceleration_velocity(msg_);
  }

private:
  ::pronto_msgs::msg::JointStateWithAcceleration msg_;
};

class Init_JointStateWithAcceleration_name
{
public:
  explicit Init_JointStateWithAcceleration_name(::pronto_msgs::msg::JointStateWithAcceleration & msg)
  : msg_(msg)
  {}
  Init_JointStateWithAcceleration_position name(::pronto_msgs::msg::JointStateWithAcceleration::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_JointStateWithAcceleration_position(msg_);
  }

private:
  ::pronto_msgs::msg::JointStateWithAcceleration msg_;
};

class Init_JointStateWithAcceleration_header
{
public:
  Init_JointStateWithAcceleration_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointStateWithAcceleration_name header(::pronto_msgs::msg::JointStateWithAcceleration::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_JointStateWithAcceleration_name(msg_);
  }

private:
  ::pronto_msgs::msg::JointStateWithAcceleration msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pronto_msgs::msg::JointStateWithAcceleration>()
{
  return pronto_msgs::msg::builder::Init_JointStateWithAcceleration_header();
}

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__JOINT_STATE_WITH_ACCELERATION__BUILDER_HPP_
