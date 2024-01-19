// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pronto_msgs:msg/FilterState.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__FILTER_STATE__BUILDER_HPP_
#define PRONTO_MSGS__MSG__DETAIL__FILTER_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pronto_msgs/msg/detail/filter_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pronto_msgs
{

namespace msg
{

namespace builder
{

class Init_FilterState_cov
{
public:
  explicit Init_FilterState_cov(::pronto_msgs::msg::FilterState & msg)
  : msg_(msg)
  {}
  ::pronto_msgs::msg::FilterState cov(::pronto_msgs::msg::FilterState::_cov_type arg)
  {
    msg_.cov = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pronto_msgs::msg::FilterState msg_;
};

class Init_FilterState_state
{
public:
  explicit Init_FilterState_state(::pronto_msgs::msg::FilterState & msg)
  : msg_(msg)
  {}
  Init_FilterState_cov state(::pronto_msgs::msg::FilterState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_FilterState_cov(msg_);
  }

private:
  ::pronto_msgs::msg::FilterState msg_;
};

class Init_FilterState_quat
{
public:
  explicit Init_FilterState_quat(::pronto_msgs::msg::FilterState & msg)
  : msg_(msg)
  {}
  Init_FilterState_state quat(::pronto_msgs::msg::FilterState::_quat_type arg)
  {
    msg_.quat = std::move(arg);
    return Init_FilterState_state(msg_);
  }

private:
  ::pronto_msgs::msg::FilterState msg_;
};

class Init_FilterState_header
{
public:
  Init_FilterState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FilterState_quat header(::pronto_msgs::msg::FilterState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FilterState_quat(msg_);
  }

private:
  ::pronto_msgs::msg::FilterState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pronto_msgs::msg::FilterState>()
{
  return pronto_msgs::msg::builder::Init_FilterState_header();
}

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__FILTER_STATE__BUILDER_HPP_
