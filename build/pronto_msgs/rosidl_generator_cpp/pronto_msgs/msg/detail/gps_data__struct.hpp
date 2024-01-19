// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pronto_msgs:msg/GPSData.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__GPS_DATA__STRUCT_HPP_
#define PRONTO_MSGS__MSG__DETAIL__GPS_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pronto_msgs__msg__GPSData __attribute__((deprecated))
#else
# define DEPRECATED__pronto_msgs__msg__GPSData __declspec(deprecated)
#endif

namespace pronto_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GPSData_
{
  using Type = GPSData_<ContainerAllocator>;

  explicit GPSData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->utime = 0ull;
      this->gps_lock = 0l;
      this->longitude = 0.0;
      this->latitude = 0.0;
      this->elev = 0.0;
      this->horizontal_accuracy = 0.0;
      this->vertical_accuracy = 0.0;
      this->num_satellites = 0ul;
      this->speed = 0.0;
      this->heading = 0.0;
      std::fill<typename std::array<double, 3>::iterator, double>(this->xyz_pos.begin(), this->xyz_pos.end(), 0.0);
      this->gps_time = 0.0;
    }
  }

  explicit GPSData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    xyz_pos(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->utime = 0ull;
      this->gps_lock = 0l;
      this->longitude = 0.0;
      this->latitude = 0.0;
      this->elev = 0.0;
      this->horizontal_accuracy = 0.0;
      this->vertical_accuracy = 0.0;
      this->num_satellites = 0ul;
      this->speed = 0.0;
      this->heading = 0.0;
      std::fill<typename std::array<double, 3>::iterator, double>(this->xyz_pos.begin(), this->xyz_pos.end(), 0.0);
      this->gps_time = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _utime_type =
    uint64_t;
  _utime_type utime;
  using _gps_lock_type =
    int32_t;
  _gps_lock_type gps_lock;
  using _longitude_type =
    double;
  _longitude_type longitude;
  using _latitude_type =
    double;
  _latitude_type latitude;
  using _elev_type =
    double;
  _elev_type elev;
  using _horizontal_accuracy_type =
    double;
  _horizontal_accuracy_type horizontal_accuracy;
  using _vertical_accuracy_type =
    double;
  _vertical_accuracy_type vertical_accuracy;
  using _num_satellites_type =
    uint32_t;
  _num_satellites_type num_satellites;
  using _speed_type =
    double;
  _speed_type speed;
  using _heading_type =
    double;
  _heading_type heading;
  using _xyz_pos_type =
    std::array<double, 3>;
  _xyz_pos_type xyz_pos;
  using _gps_time_type =
    double;
  _gps_time_type gps_time;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__utime(
    const uint64_t & _arg)
  {
    this->utime = _arg;
    return *this;
  }
  Type & set__gps_lock(
    const int32_t & _arg)
  {
    this->gps_lock = _arg;
    return *this;
  }
  Type & set__longitude(
    const double & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__latitude(
    const double & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__elev(
    const double & _arg)
  {
    this->elev = _arg;
    return *this;
  }
  Type & set__horizontal_accuracy(
    const double & _arg)
  {
    this->horizontal_accuracy = _arg;
    return *this;
  }
  Type & set__vertical_accuracy(
    const double & _arg)
  {
    this->vertical_accuracy = _arg;
    return *this;
  }
  Type & set__num_satellites(
    const uint32_t & _arg)
  {
    this->num_satellites = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__heading(
    const double & _arg)
  {
    this->heading = _arg;
    return *this;
  }
  Type & set__xyz_pos(
    const std::array<double, 3> & _arg)
  {
    this->xyz_pos = _arg;
    return *this;
  }
  Type & set__gps_time(
    const double & _arg)
  {
    this->gps_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pronto_msgs::msg::GPSData_<ContainerAllocator> *;
  using ConstRawPtr =
    const pronto_msgs::msg::GPSData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pronto_msgs::msg::GPSData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pronto_msgs::msg::GPSData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::GPSData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::GPSData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::GPSData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::GPSData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pronto_msgs::msg::GPSData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pronto_msgs::msg::GPSData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pronto_msgs__msg__GPSData
    std::shared_ptr<pronto_msgs::msg::GPSData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pronto_msgs__msg__GPSData
    std::shared_ptr<pronto_msgs::msg::GPSData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GPSData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->utime != other.utime) {
      return false;
    }
    if (this->gps_lock != other.gps_lock) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->elev != other.elev) {
      return false;
    }
    if (this->horizontal_accuracy != other.horizontal_accuracy) {
      return false;
    }
    if (this->vertical_accuracy != other.vertical_accuracy) {
      return false;
    }
    if (this->num_satellites != other.num_satellites) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->heading != other.heading) {
      return false;
    }
    if (this->xyz_pos != other.xyz_pos) {
      return false;
    }
    if (this->gps_time != other.gps_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const GPSData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GPSData_

// alias to use template instance with default allocator
using GPSData =
  pronto_msgs::msg::GPSData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__GPS_DATA__STRUCT_HPP_
