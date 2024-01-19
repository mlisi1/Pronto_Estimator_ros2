// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pronto_msgs:msg/GPSData.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__GPS_DATA__BUILDER_HPP_
#define PRONTO_MSGS__MSG__DETAIL__GPS_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pronto_msgs/msg/detail/gps_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pronto_msgs
{

namespace msg
{

namespace builder
{

class Init_GPSData_gps_time
{
public:
  explicit Init_GPSData_gps_time(::pronto_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  ::pronto_msgs::msg::GPSData gps_time(::pronto_msgs::msg::GPSData::_gps_time_type arg)
  {
    msg_.gps_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pronto_msgs::msg::GPSData msg_;
};

class Init_GPSData_xyz_pos
{
public:
  explicit Init_GPSData_xyz_pos(::pronto_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_gps_time xyz_pos(::pronto_msgs::msg::GPSData::_xyz_pos_type arg)
  {
    msg_.xyz_pos = std::move(arg);
    return Init_GPSData_gps_time(msg_);
  }

private:
  ::pronto_msgs::msg::GPSData msg_;
};

class Init_GPSData_heading
{
public:
  explicit Init_GPSData_heading(::pronto_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_xyz_pos heading(::pronto_msgs::msg::GPSData::_heading_type arg)
  {
    msg_.heading = std::move(arg);
    return Init_GPSData_xyz_pos(msg_);
  }

private:
  ::pronto_msgs::msg::GPSData msg_;
};

class Init_GPSData_speed
{
public:
  explicit Init_GPSData_speed(::pronto_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_heading speed(::pronto_msgs::msg::GPSData::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_GPSData_heading(msg_);
  }

private:
  ::pronto_msgs::msg::GPSData msg_;
};

class Init_GPSData_num_satellites
{
public:
  explicit Init_GPSData_num_satellites(::pronto_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_speed num_satellites(::pronto_msgs::msg::GPSData::_num_satellites_type arg)
  {
    msg_.num_satellites = std::move(arg);
    return Init_GPSData_speed(msg_);
  }

private:
  ::pronto_msgs::msg::GPSData msg_;
};

class Init_GPSData_vertical_accuracy
{
public:
  explicit Init_GPSData_vertical_accuracy(::pronto_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_num_satellites vertical_accuracy(::pronto_msgs::msg::GPSData::_vertical_accuracy_type arg)
  {
    msg_.vertical_accuracy = std::move(arg);
    return Init_GPSData_num_satellites(msg_);
  }

private:
  ::pronto_msgs::msg::GPSData msg_;
};

class Init_GPSData_horizontal_accuracy
{
public:
  explicit Init_GPSData_horizontal_accuracy(::pronto_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_vertical_accuracy horizontal_accuracy(::pronto_msgs::msg::GPSData::_horizontal_accuracy_type arg)
  {
    msg_.horizontal_accuracy = std::move(arg);
    return Init_GPSData_vertical_accuracy(msg_);
  }

private:
  ::pronto_msgs::msg::GPSData msg_;
};

class Init_GPSData_elev
{
public:
  explicit Init_GPSData_elev(::pronto_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_horizontal_accuracy elev(::pronto_msgs::msg::GPSData::_elev_type arg)
  {
    msg_.elev = std::move(arg);
    return Init_GPSData_horizontal_accuracy(msg_);
  }

private:
  ::pronto_msgs::msg::GPSData msg_;
};

class Init_GPSData_latitude
{
public:
  explicit Init_GPSData_latitude(::pronto_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_elev latitude(::pronto_msgs::msg::GPSData::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_GPSData_elev(msg_);
  }

private:
  ::pronto_msgs::msg::GPSData msg_;
};

class Init_GPSData_longitude
{
public:
  explicit Init_GPSData_longitude(::pronto_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_latitude longitude(::pronto_msgs::msg::GPSData::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_GPSData_latitude(msg_);
  }

private:
  ::pronto_msgs::msg::GPSData msg_;
};

class Init_GPSData_gps_lock
{
public:
  explicit Init_GPSData_gps_lock(::pronto_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_longitude gps_lock(::pronto_msgs::msg::GPSData::_gps_lock_type arg)
  {
    msg_.gps_lock = std::move(arg);
    return Init_GPSData_longitude(msg_);
  }

private:
  ::pronto_msgs::msg::GPSData msg_;
};

class Init_GPSData_utime
{
public:
  explicit Init_GPSData_utime(::pronto_msgs::msg::GPSData & msg)
  : msg_(msg)
  {}
  Init_GPSData_gps_lock utime(::pronto_msgs::msg::GPSData::_utime_type arg)
  {
    msg_.utime = std::move(arg);
    return Init_GPSData_gps_lock(msg_);
  }

private:
  ::pronto_msgs::msg::GPSData msg_;
};

class Init_GPSData_header
{
public:
  Init_GPSData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GPSData_utime header(::pronto_msgs::msg::GPSData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GPSData_utime(msg_);
  }

private:
  ::pronto_msgs::msg::GPSData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pronto_msgs::msg::GPSData>()
{
  return pronto_msgs::msg::builder::Init_GPSData_header();
}

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__GPS_DATA__BUILDER_HPP_
