// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pronto_msgs:msg/QuadrupedStance.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__QUADRUPED_STANCE__TRAITS_HPP_
#define PRONTO_MSGS__MSG__DETAIL__QUADRUPED_STANCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pronto_msgs/msg/detail/quadruped_stance__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace pronto_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const QuadrupedStance & msg,
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
    rosidl_generator_traits::value_to_yaml(msg.lf, out);
    out << ", ";
  }

  // member: rf
  {
    out << "rf: ";
    rosidl_generator_traits::value_to_yaml(msg.rf, out);
    out << ", ";
  }

  // member: lh
  {
    out << "lh: ";
    rosidl_generator_traits::value_to_yaml(msg.lh, out);
    out << ", ";
  }

  // member: rh
  {
    out << "rh: ";
    rosidl_generator_traits::value_to_yaml(msg.rh, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const QuadrupedStance & msg,
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
    out << "lf: ";
    rosidl_generator_traits::value_to_yaml(msg.lf, out);
    out << "\n";
  }

  // member: rf
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rf: ";
    rosidl_generator_traits::value_to_yaml(msg.rf, out);
    out << "\n";
  }

  // member: lh
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lh: ";
    rosidl_generator_traits::value_to_yaml(msg.lh, out);
    out << "\n";
  }

  // member: rh
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rh: ";
    rosidl_generator_traits::value_to_yaml(msg.rh, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const QuadrupedStance & msg, bool use_flow_style = false)
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
  const pronto_msgs::msg::QuadrupedStance & msg,
  std::ostream & out, size_t indentation = 0)
{
  pronto_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pronto_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pronto_msgs::msg::QuadrupedStance & msg)
{
  return pronto_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pronto_msgs::msg::QuadrupedStance>()
{
  return "pronto_msgs::msg::QuadrupedStance";
}

template<>
inline const char * name<pronto_msgs::msg::QuadrupedStance>()
{
  return "pronto_msgs/msg/QuadrupedStance";
}

template<>
struct has_fixed_size<pronto_msgs::msg::QuadrupedStance>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<pronto_msgs::msg::QuadrupedStance>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<pronto_msgs::msg::QuadrupedStance>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PRONTO_MSGS__MSG__DETAIL__QUADRUPED_STANCE__TRAITS_HPP_
