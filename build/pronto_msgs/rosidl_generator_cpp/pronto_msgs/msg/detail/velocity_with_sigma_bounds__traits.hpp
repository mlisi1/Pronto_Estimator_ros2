// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pronto_msgs:msg/VelocityWithSigmaBounds.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__TRAITS_HPP_
#define PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pronto_msgs/msg/detail/velocity_with_sigma_bounds__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'velocity_plus_one_sigma'
// Member 'velocity_minus_one_sigma'
// Member 'plus_one_sigma'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace pronto_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const VelocityWithSigmaBounds & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: velocity_plus_one_sigma
  {
    out << "velocity_plus_one_sigma: ";
    to_flow_style_yaml(msg.velocity_plus_one_sigma, out);
    out << ", ";
  }

  // member: velocity_minus_one_sigma
  {
    out << "velocity_minus_one_sigma: ";
    to_flow_style_yaml(msg.velocity_minus_one_sigma, out);
    out << ", ";
  }

  // member: plus_one_sigma
  {
    out << "plus_one_sigma: ";
    to_flow_style_yaml(msg.plus_one_sigma, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VelocityWithSigmaBounds & msg,
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

  // member: velocity_plus_one_sigma
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity_plus_one_sigma:\n";
    to_block_style_yaml(msg.velocity_plus_one_sigma, out, indentation + 2);
  }

  // member: velocity_minus_one_sigma
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity_minus_one_sigma:\n";
    to_block_style_yaml(msg.velocity_minus_one_sigma, out, indentation + 2);
  }

  // member: plus_one_sigma
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "plus_one_sigma:\n";
    to_block_style_yaml(msg.plus_one_sigma, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VelocityWithSigmaBounds & msg, bool use_flow_style = false)
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
  const pronto_msgs::msg::VelocityWithSigmaBounds & msg,
  std::ostream & out, size_t indentation = 0)
{
  pronto_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pronto_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pronto_msgs::msg::VelocityWithSigmaBounds & msg)
{
  return pronto_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pronto_msgs::msg::VelocityWithSigmaBounds>()
{
  return "pronto_msgs::msg::VelocityWithSigmaBounds";
}

template<>
inline const char * name<pronto_msgs::msg::VelocityWithSigmaBounds>()
{
  return "pronto_msgs/msg/VelocityWithSigmaBounds";
}

template<>
struct has_fixed_size<pronto_msgs::msg::VelocityWithSigmaBounds>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<pronto_msgs::msg::VelocityWithSigmaBounds>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<pronto_msgs::msg::VelocityWithSigmaBounds>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__TRAITS_HPP_
