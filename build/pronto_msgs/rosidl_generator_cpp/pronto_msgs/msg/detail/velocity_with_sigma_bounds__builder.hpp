// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pronto_msgs:msg/VelocityWithSigmaBounds.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__BUILDER_HPP_
#define PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pronto_msgs/msg/detail/velocity_with_sigma_bounds__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pronto_msgs
{

namespace msg
{

namespace builder
{

class Init_VelocityWithSigmaBounds_plus_one_sigma
{
public:
  explicit Init_VelocityWithSigmaBounds_plus_one_sigma(::pronto_msgs::msg::VelocityWithSigmaBounds & msg)
  : msg_(msg)
  {}
  ::pronto_msgs::msg::VelocityWithSigmaBounds plus_one_sigma(::pronto_msgs::msg::VelocityWithSigmaBounds::_plus_one_sigma_type arg)
  {
    msg_.plus_one_sigma = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pronto_msgs::msg::VelocityWithSigmaBounds msg_;
};

class Init_VelocityWithSigmaBounds_velocity_minus_one_sigma
{
public:
  explicit Init_VelocityWithSigmaBounds_velocity_minus_one_sigma(::pronto_msgs::msg::VelocityWithSigmaBounds & msg)
  : msg_(msg)
  {}
  Init_VelocityWithSigmaBounds_plus_one_sigma velocity_minus_one_sigma(::pronto_msgs::msg::VelocityWithSigmaBounds::_velocity_minus_one_sigma_type arg)
  {
    msg_.velocity_minus_one_sigma = std::move(arg);
    return Init_VelocityWithSigmaBounds_plus_one_sigma(msg_);
  }

private:
  ::pronto_msgs::msg::VelocityWithSigmaBounds msg_;
};

class Init_VelocityWithSigmaBounds_velocity_plus_one_sigma
{
public:
  explicit Init_VelocityWithSigmaBounds_velocity_plus_one_sigma(::pronto_msgs::msg::VelocityWithSigmaBounds & msg)
  : msg_(msg)
  {}
  Init_VelocityWithSigmaBounds_velocity_minus_one_sigma velocity_plus_one_sigma(::pronto_msgs::msg::VelocityWithSigmaBounds::_velocity_plus_one_sigma_type arg)
  {
    msg_.velocity_plus_one_sigma = std::move(arg);
    return Init_VelocityWithSigmaBounds_velocity_minus_one_sigma(msg_);
  }

private:
  ::pronto_msgs::msg::VelocityWithSigmaBounds msg_;
};

class Init_VelocityWithSigmaBounds_header
{
public:
  Init_VelocityWithSigmaBounds_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VelocityWithSigmaBounds_velocity_plus_one_sigma header(::pronto_msgs::msg::VelocityWithSigmaBounds::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VelocityWithSigmaBounds_velocity_plus_one_sigma(msg_);
  }

private:
  ::pronto_msgs::msg::VelocityWithSigmaBounds msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pronto_msgs::msg::VelocityWithSigmaBounds>()
{
  return pronto_msgs::msg::builder::Init_VelocityWithSigmaBounds_header();
}

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__BUILDER_HPP_
