// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pronto_msgs:msg/VisualOdometryUpdate.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__VISUAL_ODOMETRY_UPDATE__BUILDER_HPP_
#define PRONTO_MSGS__MSG__DETAIL__VISUAL_ODOMETRY_UPDATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pronto_msgs/msg/detail/visual_odometry_update__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pronto_msgs
{

namespace msg
{

namespace builder
{

class Init_VisualOdometryUpdate_estimate_status
{
public:
  explicit Init_VisualOdometryUpdate_estimate_status(::pronto_msgs::msg::VisualOdometryUpdate & msg)
  : msg_(msg)
  {}
  ::pronto_msgs::msg::VisualOdometryUpdate estimate_status(::pronto_msgs::msg::VisualOdometryUpdate::_estimate_status_type arg)
  {
    msg_.estimate_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pronto_msgs::msg::VisualOdometryUpdate msg_;
};

class Init_VisualOdometryUpdate_covariance
{
public:
  explicit Init_VisualOdometryUpdate_covariance(::pronto_msgs::msg::VisualOdometryUpdate & msg)
  : msg_(msg)
  {}
  Init_VisualOdometryUpdate_estimate_status covariance(::pronto_msgs::msg::VisualOdometryUpdate::_covariance_type arg)
  {
    msg_.covariance = std::move(arg);
    return Init_VisualOdometryUpdate_estimate_status(msg_);
  }

private:
  ::pronto_msgs::msg::VisualOdometryUpdate msg_;
};

class Init_VisualOdometryUpdate_relative_transform
{
public:
  explicit Init_VisualOdometryUpdate_relative_transform(::pronto_msgs::msg::VisualOdometryUpdate & msg)
  : msg_(msg)
  {}
  Init_VisualOdometryUpdate_covariance relative_transform(::pronto_msgs::msg::VisualOdometryUpdate::_relative_transform_type arg)
  {
    msg_.relative_transform = std::move(arg);
    return Init_VisualOdometryUpdate_covariance(msg_);
  }

private:
  ::pronto_msgs::msg::VisualOdometryUpdate msg_;
};

class Init_VisualOdometryUpdate_prev_timestamp
{
public:
  explicit Init_VisualOdometryUpdate_prev_timestamp(::pronto_msgs::msg::VisualOdometryUpdate & msg)
  : msg_(msg)
  {}
  Init_VisualOdometryUpdate_relative_transform prev_timestamp(::pronto_msgs::msg::VisualOdometryUpdate::_prev_timestamp_type arg)
  {
    msg_.prev_timestamp = std::move(arg);
    return Init_VisualOdometryUpdate_relative_transform(msg_);
  }

private:
  ::pronto_msgs::msg::VisualOdometryUpdate msg_;
};

class Init_VisualOdometryUpdate_curr_timestamp
{
public:
  explicit Init_VisualOdometryUpdate_curr_timestamp(::pronto_msgs::msg::VisualOdometryUpdate & msg)
  : msg_(msg)
  {}
  Init_VisualOdometryUpdate_prev_timestamp curr_timestamp(::pronto_msgs::msg::VisualOdometryUpdate::_curr_timestamp_type arg)
  {
    msg_.curr_timestamp = std::move(arg);
    return Init_VisualOdometryUpdate_prev_timestamp(msg_);
  }

private:
  ::pronto_msgs::msg::VisualOdometryUpdate msg_;
};

class Init_VisualOdometryUpdate_header
{
public:
  Init_VisualOdometryUpdate_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VisualOdometryUpdate_curr_timestamp header(::pronto_msgs::msg::VisualOdometryUpdate::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VisualOdometryUpdate_curr_timestamp(msg_);
  }

private:
  ::pronto_msgs::msg::VisualOdometryUpdate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pronto_msgs::msg::VisualOdometryUpdate>()
{
  return pronto_msgs::msg::builder::Init_VisualOdometryUpdate_header();
}

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__VISUAL_ODOMETRY_UPDATE__BUILDER_HPP_
