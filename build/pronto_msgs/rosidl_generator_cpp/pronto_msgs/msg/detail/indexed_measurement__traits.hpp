// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pronto_msgs:msg/IndexedMeasurement.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__INDEXED_MEASUREMENT__TRAITS_HPP_
#define PRONTO_MSGS__MSG__DETAIL__INDEXED_MEASUREMENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pronto_msgs/msg/detail/indexed_measurement__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace pronto_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const IndexedMeasurement & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: utime
  {
    out << "utime: ";
    rosidl_generator_traits::value_to_yaml(msg.utime, out);
    out << ", ";
  }

  // member: state_utime
  {
    out << "state_utime: ";
    rosidl_generator_traits::value_to_yaml(msg.state_utime, out);
    out << ", ";
  }

  // member: z_effective
  {
    if (msg.z_effective.size() == 0) {
      out << "z_effective: []";
    } else {
      out << "z_effective: [";
      size_t pending_items = msg.z_effective.size();
      for (auto item : msg.z_effective) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: z_indices
  {
    if (msg.z_indices.size() == 0) {
      out << "z_indices: []";
    } else {
      out << "z_indices: [";
      size_t pending_items = msg.z_indices.size();
      for (auto item : msg.z_indices) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: r_effective
  {
    if (msg.r_effective.size() == 0) {
      out << "r_effective: []";
    } else {
      out << "r_effective: [";
      size_t pending_items = msg.r_effective.size();
      for (auto item : msg.r_effective) {
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
  const IndexedMeasurement & msg,
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

  // member: utime
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utime: ";
    rosidl_generator_traits::value_to_yaml(msg.utime, out);
    out << "\n";
  }

  // member: state_utime
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state_utime: ";
    rosidl_generator_traits::value_to_yaml(msg.state_utime, out);
    out << "\n";
  }

  // member: z_effective
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.z_effective.size() == 0) {
      out << "z_effective: []\n";
    } else {
      out << "z_effective:\n";
      for (auto item : msg.z_effective) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: z_indices
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.z_indices.size() == 0) {
      out << "z_indices: []\n";
    } else {
      out << "z_indices:\n";
      for (auto item : msg.z_indices) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: r_effective
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.r_effective.size() == 0) {
      out << "r_effective: []\n";
    } else {
      out << "r_effective:\n";
      for (auto item : msg.r_effective) {
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

inline std::string to_yaml(const IndexedMeasurement & msg, bool use_flow_style = false)
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
  const pronto_msgs::msg::IndexedMeasurement & msg,
  std::ostream & out, size_t indentation = 0)
{
  pronto_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pronto_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pronto_msgs::msg::IndexedMeasurement & msg)
{
  return pronto_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pronto_msgs::msg::IndexedMeasurement>()
{
  return "pronto_msgs::msg::IndexedMeasurement";
}

template<>
inline const char * name<pronto_msgs::msg::IndexedMeasurement>()
{
  return "pronto_msgs/msg/IndexedMeasurement";
}

template<>
struct has_fixed_size<pronto_msgs::msg::IndexedMeasurement>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pronto_msgs::msg::IndexedMeasurement>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pronto_msgs::msg::IndexedMeasurement>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PRONTO_MSGS__MSG__DETAIL__INDEXED_MEASUREMENT__TRAITS_HPP_
