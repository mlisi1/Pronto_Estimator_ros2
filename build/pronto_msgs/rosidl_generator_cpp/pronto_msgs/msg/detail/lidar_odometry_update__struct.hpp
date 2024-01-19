// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pronto_msgs:msg/LidarOdometryUpdate.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__LIDAR_ODOMETRY_UPDATE__STRUCT_HPP_
#define PRONTO_MSGS__MSG__DETAIL__LIDAR_ODOMETRY_UPDATE__STRUCT_HPP_

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
// Member 'curr_timestamp'
// Member 'prev_timestamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"
// Member 'relative_transform'
#include "geometry_msgs/msg/detail/transform__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pronto_msgs__msg__LidarOdometryUpdate __attribute__((deprecated))
#else
# define DEPRECATED__pronto_msgs__msg__LidarOdometryUpdate __declspec(deprecated)
#endif

namespace pronto_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LidarOdometryUpdate_
{
  using Type = LidarOdometryUpdate_<ContainerAllocator>;

  explicit LidarOdometryUpdate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    curr_timestamp(_init),
    prev_timestamp(_init),
    relative_transform(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 36>::iterator, double>(this->covariance.begin(), this->covariance.end(), 0.0);
    }
  }

  explicit LidarOdometryUpdate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    curr_timestamp(_alloc, _init),
    prev_timestamp(_alloc, _init),
    relative_transform(_alloc, _init),
    covariance(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 36>::iterator, double>(this->covariance.begin(), this->covariance.end(), 0.0);
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _curr_timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _curr_timestamp_type curr_timestamp;
  using _prev_timestamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _prev_timestamp_type prev_timestamp;
  using _relative_transform_type =
    geometry_msgs::msg::Transform_<ContainerAllocator>;
  _relative_transform_type relative_transform;
  using _covariance_type =
    std::array<double, 36>;
  _covariance_type covariance;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__curr_timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->curr_timestamp = _arg;
    return *this;
  }
  Type & set__prev_timestamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->prev_timestamp = _arg;
    return *this;
  }
  Type & set__relative_transform(
    const geometry_msgs::msg::Transform_<ContainerAllocator> & _arg)
  {
    this->relative_transform = _arg;
    return *this;
  }
  Type & set__covariance(
    const std::array<double, 36> & _arg)
  {
    this->covariance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pronto_msgs::msg::LidarOdometryUpdate_<ContainerAllocator> *;
  using ConstRawPtr =
    const pronto_msgs::msg::LidarOdometryUpdate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pronto_msgs::msg::LidarOdometryUpdate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pronto_msgs::msg::LidarOdometryUpdate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::LidarOdometryUpdate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::LidarOdometryUpdate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::LidarOdometryUpdate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::LidarOdometryUpdate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pronto_msgs::msg::LidarOdometryUpdate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pronto_msgs::msg::LidarOdometryUpdate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pronto_msgs__msg__LidarOdometryUpdate
    std::shared_ptr<pronto_msgs::msg::LidarOdometryUpdate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pronto_msgs__msg__LidarOdometryUpdate
    std::shared_ptr<pronto_msgs::msg::LidarOdometryUpdate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LidarOdometryUpdate_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->curr_timestamp != other.curr_timestamp) {
      return false;
    }
    if (this->prev_timestamp != other.prev_timestamp) {
      return false;
    }
    if (this->relative_transform != other.relative_transform) {
      return false;
    }
    if (this->covariance != other.covariance) {
      return false;
    }
    return true;
  }
  bool operator!=(const LidarOdometryUpdate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LidarOdometryUpdate_

// alias to use template instance with default allocator
using LidarOdometryUpdate =
  pronto_msgs::msg::LidarOdometryUpdate_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__LIDAR_ODOMETRY_UPDATE__STRUCT_HPP_
