// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pronto_msgs:msg/VisualOdometryUpdate.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__VISUAL_ODOMETRY_UPDATE__TRAITS_HPP_
#define PRONTO_MSGS__MSG__DETAIL__VISUAL_ODOMETRY_UPDATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pronto_msgs/msg/detail/visual_odometry_update__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'curr_timestamp'
// Member 'prev_timestamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"
// Member 'relative_transform'
#include "geometry_msgs/msg/detail/transform__traits.hpp"

namespace pronto_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const VisualOdometryUpdate & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: curr_timestamp
  {
    out << "curr_timestamp: ";
    to_flow_style_yaml(msg.curr_timestamp, out);
    out << ", ";
  }

  // member: prev_timestamp
  {
    out << "prev_timestamp: ";
    to_flow_style_yaml(msg.prev_timestamp, out);
    out << ", ";
  }

  // member: relative_transform
  {
    out << "relative_transform: ";
    to_flow_style_yaml(msg.relative_transform, out);
    out << ", ";
  }

  // member: covariance
  {
    if (msg.covariance.size() == 0) {
      out << "covariance: []";
    } else {
      out << "covariance: [";
      size_t pending_items = msg.covariance.size();
      for (auto item : msg.covariance) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: estimate_status
  {
    out << "estimate_status: ";
    rosidl_generator_traits::value_to_yaml(msg.estimate_status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VisualOdometryUpdate & msg,
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

  // member: curr_timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "curr_timestamp:\n";
    to_block_style_yaml(msg.curr_timestamp, out, indentation + 2);
  }

  // member: prev_timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "prev_timestamp:\n";
    to_block_style_yaml(msg.prev_timestamp, out, indentation + 2);
  }

  // member: relative_transform
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "relative_transform:\n";
    to_block_style_yaml(msg.relative_transform, out, indentation + 2);
  }

  // member: covariance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.covariance.size() == 0) {
      out << "covariance: []\n";
    } else {
      out << "covariance:\n";
      for (auto item : msg.covariance) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: estimate_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "estimate_status: ";
    rosidl_generator_traits::value_to_yaml(msg.estimate_status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VisualOdometryUpdate & msg, bool use_flow_style = false)
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
  const pronto_msgs::msg::VisualOdometryUpdate & msg,
  std::ostream & out, size_t indentation = 0)
{
  pronto_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pronto_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pronto_msgs::msg::VisualOdometryUpdate & msg)
{
  return pronto_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pronto_msgs::msg::VisualOdometryUpdate>()
{
  return "pronto_msgs::msg::VisualOdometryUpdate";
}

template<>
inline const char * name<pronto_msgs::msg::VisualOdometryUpdate>()
{
  return "pronto_msgs/msg/VisualOdometryUpdate";
}

template<>
struct has_fixed_size<pronto_msgs::msg::VisualOdometryUpdate>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value && has_fixed_size<geometry_msgs::msg::Transform>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<pronto_msgs::msg::VisualOdometryUpdate>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value && has_bounded_size<geometry_msgs::msg::Transform>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<pronto_msgs::msg::VisualOdometryUpdate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PRONTO_MSGS__MSG__DETAIL__VISUAL_ODOMETRY_UPDATE__TRAITS_HPP_
