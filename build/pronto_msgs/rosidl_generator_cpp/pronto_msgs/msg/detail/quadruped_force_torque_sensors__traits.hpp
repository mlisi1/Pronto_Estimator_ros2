// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pronto_msgs:msg/QuadrupedForceTorqueSensors.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__QUADRUPED_FORCE_TORQUE_SENSORS__TRAITS_HPP_
#define PRONTO_MSGS__MSG__DETAIL__QUADRUPED_FORCE_TORQUE_SENSORS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pronto_msgs/msg/detail/quadruped_force_torque_sensors__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'lf'
// Member 'rf'
// Member 'lh'
// Member 'rh'
#include "geometry_msgs/msg/detail/wrench__traits.hpp"

namespace pronto_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const QuadrupedForceTorqueSensors & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: lf
  {
    out << "lf: ";
    to_flow_style_yaml(msg.lf, out);
    out << ", ";
  }

  // member: rf
  {
    out << "rf: ";
    to_flow_style_yaml(msg.rf, out);
    out << ", ";
  }

  // member: lh
  {
    out << "lh: ";
    to_flow_style_yaml(msg.lh, out);
    out << ", ";
  }

  // member: rh
  {
    out << "rh: ";
    to_flow_style_yaml(msg.rh, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const QuadrupedForceTorqueSensors & msg,
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

  // member: lf
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lf:\n";
    to_block_style_yaml(msg.lf, out, indentation + 2);
  }

  // member: rf
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rf:\n";
    to_block_style_yaml(msg.rf, out, indentation + 2);
  }

  // member: lh
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lh:\n";
    to_block_style_yaml(msg.lh, out, indentation + 2);
  }

  // member: rh
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rh:\n";
    to_block_style_yaml(msg.rh, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const QuadrupedForceTorqueSensors & msg, bool use_flow_style = false)
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
  const pronto_msgs::msg::QuadrupedForceTorqueSensors & msg,
  std::ostream & out, size_t indentation = 0)
{
  pronto_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pronto_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pronto_msgs::msg::QuadrupedForceTorqueSensors & msg)
{
  return pronto_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pronto_msgs::msg::QuadrupedForceTorqueSensors>()
{
  return "pronto_msgs::msg::QuadrupedForceTorqueSensors";
}

template<>
inline const char * name<pronto_msgs::msg::QuadrupedForceTorqueSensors>()
{
  return "pronto_msgs/msg/QuadrupedForceTorqueSensors";
}

template<>
struct has_fixed_size<pronto_msgs::msg::QuadrupedForceTorqueSensors>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Wrench>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<pronto_msgs::msg::QuadrupedForceTorqueSensors>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Wrench>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<pronto_msgs::msg::QuadrupedForceTorqueSensors>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PRONTO_MSGS__MSG__DETAIL__QUADRUPED_FORCE_TORQUE_SENSORS__TRAITS_HPP_
