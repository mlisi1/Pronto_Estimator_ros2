// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pronto_msgs:msg/GPSData.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__GPS_DATA__TRAITS_HPP_
#define PRONTO_MSGS__MSG__DETAIL__GPS_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pronto_msgs/msg/detail/gps_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace pronto_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const GPSData & msg,
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

  // member: gps_lock
  {
    out << "gps_lock: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_lock, out);
    out << ", ";
  }

  // member: longitude
  {
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << ", ";
  }

  // member: latitude
  {
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << ", ";
  }

  // member: elev
  {
    out << "elev: ";
    rosidl_generator_traits::value_to_yaml(msg.elev, out);
    out << ", ";
  }

  // member: horizontal_accuracy
  {
    out << "horizontal_accuracy: ";
    rosidl_generator_traits::value_to_yaml(msg.horizontal_accuracy, out);
    out << ", ";
  }

  // member: vertical_accuracy
  {
    out << "vertical_accuracy: ";
    rosidl_generator_traits::value_to_yaml(msg.vertical_accuracy, out);
    out << ", ";
  }

  // member: num_satellites
  {
    out << "num_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.num_satellites, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: heading
  {
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << ", ";
  }

  // member: xyz_pos
  {
    if (msg.xyz_pos.size() == 0) {
      out << "xyz_pos: []";
    } else {
      out << "xyz_pos: [";
      size_t pending_items = msg.xyz_pos.size();
      for (auto item : msg.xyz_pos) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: gps_time
  {
    out << "gps_time: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GPSData & msg,
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

  // member: gps_lock
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gps_lock: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_lock, out);
    out << "\n";
  }

  // member: longitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << "\n";
  }

  // member: latitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << "\n";
  }

  // member: elev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "elev: ";
    rosidl_generator_traits::value_to_yaml(msg.elev, out);
    out << "\n";
  }

  // member: horizontal_accuracy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "horizontal_accuracy: ";
    rosidl_generator_traits::value_to_yaml(msg.horizontal_accuracy, out);
    out << "\n";
  }

  // member: vertical_accuracy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vertical_accuracy: ";
    rosidl_generator_traits::value_to_yaml(msg.vertical_accuracy, out);
    out << "\n";
  }

  // member: num_satellites
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.num_satellites, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading: ";
    rosidl_generator_traits::value_to_yaml(msg.heading, out);
    out << "\n";
  }

  // member: xyz_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.xyz_pos.size() == 0) {
      out << "xyz_pos: []\n";
    } else {
      out << "xyz_pos:\n";
      for (auto item : msg.xyz_pos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: gps_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gps_time: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GPSData & msg, bool use_flow_style = false)
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
  const pronto_msgs::msg::GPSData & msg,
  std::ostream & out, size_t indentation = 0)
{
  pronto_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pronto_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pronto_msgs::msg::GPSData & msg)
{
  return pronto_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pronto_msgs::msg::GPSData>()
{
  return "pronto_msgs::msg::GPSData";
}

template<>
inline const char * name<pronto_msgs::msg::GPSData>()
{
  return "pronto_msgs/msg/GPSData";
}

template<>
struct has_fixed_size<pronto_msgs::msg::GPSData>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<pronto_msgs::msg::GPSData>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<pronto_msgs::msg::GPSData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PRONTO_MSGS__MSG__DETAIL__GPS_DATA__TRAITS_HPP_
