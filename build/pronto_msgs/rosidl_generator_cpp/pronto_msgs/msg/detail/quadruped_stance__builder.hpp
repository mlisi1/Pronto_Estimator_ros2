// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pronto_msgs:msg/QuadrupedStance.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__QUADRUPED_STANCE__BUILDER_HPP_
#define PRONTO_MSGS__MSG__DETAIL__QUADRUPED_STANCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pronto_msgs/msg/detail/quadruped_stance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pronto_msgs
{

namespace msg
{

namespace builder
{

class Init_QuadrupedStance_rh
{
public:
  explicit Init_QuadrupedStance_rh(::pronto_msgs::msg::QuadrupedStance & msg)
  : msg_(msg)
  {}
  ::pronto_msgs::msg::QuadrupedStance rh(::pronto_msgs::msg::QuadrupedStance::_rh_type arg)
  {
    msg_.rh = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pronto_msgs::msg::QuadrupedStance msg_;
};

class Init_QuadrupedStance_lh
{
public:
  explicit Init_QuadrupedStance_lh(::pronto_msgs::msg::QuadrupedStance & msg)
  : msg_(msg)
  {}
  Init_QuadrupedStance_rh lh(::pronto_msgs::msg::QuadrupedStance::_lh_type arg)
  {
    msg_.lh = std::move(arg);
    return Init_QuadrupedStance_rh(msg_);
  }

private:
  ::pronto_msgs::msg::QuadrupedStance msg_;
};

class Init_QuadrupedStance_rf
{
public:
  explicit Init_QuadrupedStance_rf(::pronto_msgs::msg::QuadrupedStance & msg)
  : msg_(msg)
  {}
  Init_QuadrupedStance_lh rf(::pronto_msgs::msg::QuadrupedStance::_rf_type arg)
  {
    msg_.rf = std::move(arg);
    return Init_QuadrupedStance_lh(msg_);
  }

private:
  ::pronto_msgs::msg::QuadrupedStance msg_;
};

class Init_QuadrupedStance_lf
{
public:
  explicit Init_QuadrupedStance_lf(::pronto_msgs::msg::QuadrupedStance & msg)
  : msg_(msg)
  {}
  Init_QuadrupedStance_rf lf(::pronto_msgs::msg::QuadrupedStance::_lf_type arg)
  {
    msg_.lf = std::move(arg);
    return Init_QuadrupedStance_rf(msg_);
  }

private:
  ::pronto_msgs::msg::QuadrupedStance msg_;
};

class Init_QuadrupedStance_header
{
public:
  Init_QuadrupedStance_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_QuadrupedStance_lf header(::pronto_msgs::msg::QuadrupedStance::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_QuadrupedStance_lf(msg_);
  }

private:
  ::pronto_msgs::msg::QuadrupedStance msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pronto_msgs::msg::QuadrupedStance>()
{
  return pronto_msgs::msg::builder::Init_QuadrupedStance_header();
}

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__QUADRUPED_STANCE__BUILDER_HPP_
