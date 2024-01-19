// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pronto_msgs:msg/ControllerFootContact.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__CONTROLLER_FOOT_CONTACT__TRAITS_HPP_
#define PRONTO_MSGS__MSG__DETAIL__CONTROLLER_FOOT_CONTACT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pronto_msgs/msg/detail/controller_foot_contact__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace pronto_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ControllerFootContact & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: num_right_foot_contacts
  {
    out << "num_right_foot_contacts: ";
    rosidl_generator_traits::value_to_yaml(msg.num_right_foot_contacts, out);
    out << ", ";
  }

  // member: right_foot_contacts
  {
    if (msg.right_foot_contacts.size() == 0) {
      out << "right_foot_contacts: []";
    } else {
      out << "right_foot_contacts: [";
      size_t pending_items = msg.right_foot_contacts.size();
      for (auto item : msg.right_foot_contacts) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: num_left_foot_contacts
  {
    out << "num_left_foot_contacts: ";
    rosidl_generator_traits::value_to_yaml(msg.num_left_foot_contacts, out);
    out << ", ";
  }

  // member: left_foot_contacts
  {
    if (msg.left_foot_contacts.size() == 0) {
      out << "left_foot_contacts: []";
    } else {
      out << "left_foot_contacts: [";
      size_t pending_items = msg.left_foot_contacts.size();
      for (auto item : msg.left_foot_contacts) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ControllerFootContact & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: num_right_foot_contacts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_right_foot_contacts: ";
    rosidl_generator_traits::value_to_yaml(msg.num_right_foot_contacts, out);
    out << "\n";
  }

  // member: right_foot_contacts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.right_foot_contacts.size() == 0) {
      out << "right_foot_contacts: []\n";
    } else {
      out << "right_foot_contacts:\n";
      for (auto item : msg.right_foot_contacts) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: num_left_foot_contacts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_left_foot_contacts: ";
    rosidl_generator_traits::value_to_yaml(msg.num_left_foot_contacts, out);
    out << "\n";
  }

  // member: left_foot_contacts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.left_foot_contacts.size() == 0) {
      out << "left_foot_contacts: []\n";
    } else {
      out << "left_foot_contacts:\n";
      for (auto item : msg.left_foot_contacts) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ControllerFootContact & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace pronto_msgs

namespace rosidl_generator_traits
{

[[deprecated("use pronto_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pronto_msgs::msg::ControllerFootContact & msg,
  std::ostream & out, size_t indentation = 0)
{
  pronto_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pronto_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pronto_msgs::msg::ControllerFootContact & msg)
{
  return pronto_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pronto_msgs::msg::ControllerFootContact>()
{
  return "pronto_msgs::msg::ControllerFootContact";
}

template<>
inline const char * name<pronto_msgs::msg::ControllerFootContact>()
{
  return "pronto_msgs/msg/ControllerFootContact";
}

template<>
struct has_fixed_size<pronto_msgs::msg::ControllerFootContact>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pronto_msgs::msg::ControllerFootContact>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pronto_msgs::msg::ControllerFootContact>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PRONTO_MSGS__MSG__DETAIL__CONTROLLER_FOOT_CONTACT__TRAITS_HPP_
