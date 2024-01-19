// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pronto_msgs:msg/ControllerFootContact.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__CONTROLLER_FOOT_CONTACT__BUILDER_HPP_
#define PRONTO_MSGS__MSG__DETAIL__CONTROLLER_FOOT_CONTACT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pronto_msgs/msg/detail/controller_foot_contact__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pronto_msgs
{

namespace msg
{

namespace builder
{

class Init_ControllerFootContact_left_foot_contacts
{
public:
  explicit Init_ControllerFootContact_left_foot_contacts(::pronto_msgs::msg::ControllerFootContact & msg)
  : msg_(msg)
  {}
  ::pronto_msgs::msg::ControllerFootContact left_foot_contacts(::pronto_msgs::msg::ControllerFootContact::_left_foot_contacts_type arg)
  {
    msg_.left_foot_contacts = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pronto_msgs::msg::ControllerFootContact msg_;
};

class Init_ControllerFootContact_num_left_foot_contacts
{
public:
  explicit Init_ControllerFootContact_num_left_foot_contacts(::pronto_msgs::msg::ControllerFootContact & msg)
  : msg_(msg)
  {}
  Init_ControllerFootContact_left_foot_contacts num_left_foot_contacts(::pronto_msgs::msg::ControllerFootContact::_num_left_foot_contacts_type arg)
  {
    msg_.num_left_foot_contacts = std::move(arg);
    return Init_ControllerFootContact_left_foot_contacts(msg_);
  }

private:
  ::pronto_msgs::msg::ControllerFootContact msg_;
};

class Init_ControllerFootContact_right_foot_contacts
{
public:
  explicit Init_ControllerFootContact_right_foot_contacts(::pronto_msgs::msg::ControllerFootContact & msg)
  : msg_(msg)
  {}
  Init_ControllerFootContact_num_left_foot_contacts right_foot_contacts(::pronto_msgs::msg::ControllerFootContact::_right_foot_contacts_type arg)
  {
    msg_.right_foot_contacts = std::move(arg);
    return Init_ControllerFootContact_num_left_foot_contacts(msg_);
  }

private:
  ::pronto_msgs::msg::ControllerFootContact msg_;
};

class Init_ControllerFootContact_num_right_foot_contacts
{
public:
  explicit Init_ControllerFootContact_num_right_foot_contacts(::pronto_msgs::msg::ControllerFootContact & msg)
  : msg_(msg)
  {}
  Init_ControllerFootContact_right_foot_contacts num_right_foot_contacts(::pronto_msgs::msg::ControllerFootContact::_num_right_foot_contacts_type arg)
  {
    msg_.num_right_foot_contacts = std::move(arg);
    return Init_ControllerFootContact_right_foot_contacts(msg_);
  }

private:
  ::pronto_msgs::msg::ControllerFootContact msg_;
};

class Init_ControllerFootContact_header
{
public:
  Init_ControllerFootContact_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ControllerFootContact_num_right_foot_contacts header(::pronto_msgs::msg::ControllerFootContact::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ControllerFootContact_num_right_foot_contacts(msg_);
  }

private:
  ::pronto_msgs::msg::ControllerFootContact msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pronto_msgs::msg::ControllerFootContact>()
{
  return pronto_msgs::msg::builder::Init_ControllerFootContact_header();
}

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__CONTROLLER_FOOT_CONTACT__BUILDER_HPP_
