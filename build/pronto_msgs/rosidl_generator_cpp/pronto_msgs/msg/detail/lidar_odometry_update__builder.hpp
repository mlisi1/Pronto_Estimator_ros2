// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pronto_msgs:msg/LidarOdometryUpdate.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__LIDAR_ODOMETRY_UPDATE__BUILDER_HPP_
#define PRONTO_MSGS__MSG__DETAIL__LIDAR_ODOMETRY_UPDATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pronto_msgs/msg/detail/lidar_odometry_update__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pronto_msgs
{

namespace msg
{

namespace builder
{

class Init_LidarOdometryUpdate_covariance
{
public:
  explicit Init_LidarOdometryUpdate_covariance(::pronto_msgs::msg::LidarOdometryUpdate & msg)
  : msg_(msg)
  {}
  ::pronto_msgs::msg::LidarOdometryUpdate covariance(::pronto_msgs::msg::LidarOdometryUpdate::_covariance_type arg)
  {
    msg_.covariance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pronto_msgs::msg::LidarOdometryUpdate msg_;
};

class Init_LidarOdometryUpdate_relative_transform
{
public:
  explicit Init_LidarOdometryUpdate_relative_transform(::pronto_msgs::msg::LidarOdometryUpdate & msg)
  : msg_(msg)
  {}
  Init_LidarOdometryUpdate_covariance relative_transform(::pronto_msgs::msg::LidarOdometryUpdate::_relative_transform_type arg)
  {
    msg_.relative_transform = std::move(arg);
    return Init_LidarOdometryUpdate_covariance(msg_);
  }

private:
  ::pronto_msgs::msg::LidarOdometryUpdate msg_;
};

class Init_LidarOdometryUpdate_prev_timestamp
{
public:
  explicit Init_LidarOdometryUpdate_prev_timestamp(::pronto_msgs::msg::LidarOdometryUpdate & msg)
  : msg_(msg)
  {}
  Init_LidarOdometryUpdate_relative_transform prev_timestamp(::pronto_msgs::msg::LidarOdometryUpdate::_prev_timestamp_type arg)
  {
    msg_.prev_timestamp = std::move(arg);
    return Init_LidarOdometryUpdate_relative_transform(msg_);
  }

private:
  ::pronto_msgs::msg::LidarOdometryUpdate msg_;
};

class Init_LidarOdometryUpdate_curr_timestamp
{
public:
  explicit Init_LidarOdometryUpdate_curr_timestamp(::pronto_msgs::msg::LidarOdometryUpdate & msg)
  : msg_(msg)
  {}
  Init_LidarOdometryUpdate_prev_timestamp curr_timestamp(::pronto_msgs::msg::LidarOdometryUpdate::_curr_timestamp_type arg)
  {
    msg_.curr_timestamp = std::move(arg);
    return Init_LidarOdometryUpdate_prev_timestamp(msg_);
  }

private:
  ::pronto_msgs::msg::LidarOdometryUpdate msg_;
};

class Init_LidarOdometryUpdate_header
{
public:
  Init_LidarOdometryUpdate_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LidarOdometryUpdate_curr_timestamp header(::pronto_msgs::msg::LidarOdometryUpdate::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LidarOdometryUpdate_curr_timestamp(msg_);
  }

private:
  ::pronto_msgs::msg::LidarOdometryUpdate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pronto_msgs::msg::LidarOdometryUpdate>()
{
  return pronto_msgs::msg::builder::Init_LidarOdometryUpdate_header();
}

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__LIDAR_ODOMETRY_UPDATE__BUILDER_HPP_
