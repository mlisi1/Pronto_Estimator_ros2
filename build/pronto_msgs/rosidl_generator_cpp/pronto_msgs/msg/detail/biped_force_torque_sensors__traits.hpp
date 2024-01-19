// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pronto_msgs:msg/BipedForceTorqueSensors.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__BIPED_FORCE_TORQUE_SENSORS__TRAITS_HPP_
#define PRONTO_MSGS__MSG__DETAIL__BIPED_FORCE_TORQUE_SENSORS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pronto_msgs/msg/detail/biped_force_torque_sensors__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'l_foot'
// Member 'r_foot'
// Member 'l_hand'
// Member 'r_hand'
#include "geometry_msgs/msg/detail/wrench__traits.hpp"

namespace pronto_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BipedForceTorqueSensors & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: l_foot
  {
    out << "l_foot: ";
    to_flow_style_yaml(msg.l_foot, out);
    out << ", ";
  }

  // member: r_foot
  {
    out << "r_foot: ";
    to_flow_style_yaml(msg.r_foot, out);
    out << ", ";
  }

  // member: l_hand
  {
    out << "l_hand: ";
    to_flow_style_yaml(msg.l_hand, out);
    out << ", ";
  }

  // member: r_hand
  {
    out << "r_hand: ";
    to_flow_style_yaml(msg.r_hand, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BipedForceTorqueSensors & msg,
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

  // member: l_foot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "l_foot:\n";
    to_block_style_yaml(msg.l_foot, out, indentation + 2);
  }

  // member: r_foot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r_foot:\n";
    to_block_style_yaml(msg.r_foot, out, indentation + 2);
  }

  // member: l_hand
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "l_hand:\n";
    to_block_style_yaml(msg.l_hand, out, indentation + 2);
  }

  // member: r_hand
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "r_hand:\n";
    to_block_style_yaml(msg.r_hand, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BipedForceTorqueSensors & msg, bool use_flow_style = false)
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
  const pronto_msgs::msg::BipedForceTorqueSensors & msg,
  std::ostream & out, size_t indentation = 0)
{
  pronto_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pronto_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pronto_msgs::msg::BipedForceTorqueSensors & msg)
{
  return pronto_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pronto_msgs::msg::BipedForceTorqueSensors>()
{
  return "pronto_msgs::msg::BipedForceTorqueSensors";
}

template<>
inline const char * name<pronto_msgs::msg::BipedForceTorqueSensors>()
{
  return "pronto_msgs/msg/BipedForceTorqueSensors";
}

template<>
struct has_fixed_size<pronto_msgs::msg::BipedForceTorqueSensors>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Wrench>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<pronto_msgs::msg::BipedForceTorqueSensors>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Wrench>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<pronto_msgs::msg::BipedForceTorqueSensors>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PRONTO_MSGS__MSG__DETAIL__BIPED_FORCE_TORQUE_SENSORS__TRAITS_HPP_
