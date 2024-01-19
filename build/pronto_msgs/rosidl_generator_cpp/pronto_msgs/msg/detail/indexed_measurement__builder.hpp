// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pronto_msgs:msg/IndexedMeasurement.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__INDEXED_MEASUREMENT__BUILDER_HPP_
#define PRONTO_MSGS__MSG__DETAIL__INDEXED_MEASUREMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pronto_msgs/msg/detail/indexed_measurement__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pronto_msgs
{

namespace msg
{

namespace builder
{

class Init_IndexedMeasurement_r_effective
{
public:
  explicit Init_IndexedMeasurement_r_effective(::pronto_msgs::msg::IndexedMeasurement & msg)
  : msg_(msg)
  {}
  ::pronto_msgs::msg::IndexedMeasurement r_effective(::pronto_msgs::msg::IndexedMeasurement::_r_effective_type arg)
  {
    msg_.r_effective = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pronto_msgs::msg::IndexedMeasurement msg_;
};

class Init_IndexedMeasurement_z_indices
{
public:
  explicit Init_IndexedMeasurement_z_indices(::pronto_msgs::msg::IndexedMeasurement & msg)
  : msg_(msg)
  {}
  Init_IndexedMeasurement_r_effective z_indices(::pronto_msgs::msg::IndexedMeasurement::_z_indices_type arg)
  {
    msg_.z_indices = std::move(arg);
    return Init_IndexedMeasurement_r_effective(msg_);
  }

private:
  ::pronto_msgs::msg::IndexedMeasurement msg_;
};

class Init_IndexedMeasurement_z_effective
{
public:
  explicit Init_IndexedMeasurement_z_effective(::pronto_msgs::msg::IndexedMeasurement & msg)
  : msg_(msg)
  {}
  Init_IndexedMeasurement_z_indices z_effective(::pronto_msgs::msg::IndexedMeasurement::_z_effective_type arg)
  {
    msg_.z_effective = std::move(arg);
    return Init_IndexedMeasurement_z_indices(msg_);
  }

private:
  ::pronto_msgs::msg::IndexedMeasurement msg_;
};

class Init_IndexedMeasurement_state_utime
{
public:
  explicit Init_IndexedMeasurement_state_utime(::pronto_msgs::msg::IndexedMeasurement & msg)
  : msg_(msg)
  {}
  Init_IndexedMeasurement_z_effective state_utime(::pronto_msgs::msg::IndexedMeasurement::_state_utime_type arg)
  {
    msg_.state_utime = std::move(arg);
    return Init_IndexedMeasurement_z_effective(msg_);
  }

private:
  ::pronto_msgs::msg::IndexedMeasurement msg_;
};

class Init_IndexedMeasurement_utime
{
public:
  explicit Init_IndexedMeasurement_utime(::pronto_msgs::msg::IndexedMeasurement & msg)
  : msg_(msg)
  {}
  Init_IndexedMeasurement_state_utime utime(::pronto_msgs::msg::IndexedMeasurement::_utime_type arg)
  {
    msg_.utime = std::move(arg);
    return Init_IndexedMeasurement_state_utime(msg_);
  }

private:
  ::pronto_msgs::msg::IndexedMeasurement msg_;
};

class Init_IndexedMeasurement_header
{
public:
  Init_IndexedMeasurement_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IndexedMeasurement_utime header(::pronto_msgs::msg::IndexedMeasurement::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_IndexedMeasurement_utime(msg_);
  }

private:
  ::pronto_msgs::msg::IndexedMeasurement msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pronto_msgs::msg::IndexedMeasurement>()
{
  return pronto_msgs::msg::builder::Init_IndexedMeasurement_header();
}

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__INDEXED_MEASUREMENT__BUILDER_HPP_
