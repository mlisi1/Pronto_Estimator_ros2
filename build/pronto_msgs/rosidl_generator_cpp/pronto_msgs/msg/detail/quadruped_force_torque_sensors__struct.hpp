// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pronto_msgs:msg/QuadrupedForceTorqueSensors.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__QUADRUPED_FORCE_TORQUE_SENSORS__STRUCT_HPP_
#define PRONTO_MSGS__MSG__DETAIL__QUADRUPED_FORCE_TORQUE_SENSORS__STRUCT_HPP_

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
// Member 'lf'
// Member 'rf'
// Member 'lh'
// Member 'rh'
#include "geometry_msgs/msg/detail/wrench__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pronto_msgs__msg__QuadrupedForceTorqueSensors __attribute__((deprecated))
#else
# define DEPRECATED__pronto_msgs__msg__QuadrupedForceTorqueSensors __declspec(deprecated)
#endif

namespace pronto_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct QuadrupedForceTorqueSensors_
{
  using Type = QuadrupedForceTorqueSensors_<ContainerAllocator>;

  explicit QuadrupedForceTorqueSensors_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    lf(_init),
    rf(_init),
    lh(_init),
    rh(_init)
  {
    (void)_init;
  }

  explicit QuadrupedForceTorqueSensors_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    lf(_alloc, _init),
    rf(_alloc, _init),
    lh(_alloc, _init),
    rh(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _lf_type =
    geometry_msgs::msg::Wrench_<ContainerAllocator>;
  _lf_type lf;
  using _rf_type =
    geometry_msgs::msg::Wrench_<ContainerAllocator>;
  _rf_type rf;
  using _lh_type =
    geometry_msgs::msg::Wrench_<ContainerAllocator>;
  _lh_type lh;
  using _rh_type =
    geometry_msgs::msg::Wrench_<ContainerAllocator>;
  _rh_type rh;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__lf(
    const geometry_msgs::msg::Wrench_<ContainerAllocator> & _arg)
  {
    this->lf = _arg;
    return *this;
  }
  Type & set__rf(
    const geometry_msgs::msg::Wrench_<ContainerAllocator> & _arg)
  {
    this->rf = _arg;
    return *this;
  }
  Type & set__lh(
    const geometry_msgs::msg::Wrench_<ContainerAllocator> & _arg)
  {
    this->lh = _arg;
    return *this;
  }
  Type & set__rh(
    const geometry_msgs::msg::Wrench_<ContainerAllocator> & _arg)
  {
    this->rh = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pronto_msgs::msg::QuadrupedForceTorqueSensors_<ContainerAllocator> *;
  using ConstRawPtr =
    const pronto_msgs::msg::QuadrupedForceTorqueSensors_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pronto_msgs::msg::QuadrupedForceTorqueSensors_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pronto_msgs::msg::QuadrupedForceTorqueSensors_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::QuadrupedForceTorqueSensors_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::QuadrupedForceTorqueSensors_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::QuadrupedForceTorqueSensors_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::QuadrupedForceTorqueSensors_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pronto_msgs::msg::QuadrupedForceTorqueSensors_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pronto_msgs::msg::QuadrupedForceTorqueSensors_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pronto_msgs__msg__QuadrupedForceTorqueSensors
    std::shared_ptr<pronto_msgs::msg::QuadrupedForceTorqueSensors_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pronto_msgs__msg__QuadrupedForceTorqueSensors
    std::shared_ptr<pronto_msgs::msg::QuadrupedForceTorqueSensors_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const QuadrupedForceTorqueSensors_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->lf != other.lf) {
      return false;
    }
    if (this->rf != other.rf) {
      return false;
    }
    if (this->lh != other.lh) {
      return false;
    }
    if (this->rh != other.rh) {
      return false;
    }
    return true;
  }
  bool operator!=(const QuadrupedForceTorqueSensors_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct QuadrupedForceTorqueSensors_

// alias to use template instance with default allocator
using QuadrupedForceTorqueSensors =
  pronto_msgs::msg::QuadrupedForceTorqueSensors_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__QUADRUPED_FORCE_TORQUE_SENSORS__STRUCT_HPP_
