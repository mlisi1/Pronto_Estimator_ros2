// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pronto_msgs:msg/BipedForceTorqueSensors.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__BIPED_FORCE_TORQUE_SENSORS__STRUCT_HPP_
#define PRONTO_MSGS__MSG__DETAIL__BIPED_FORCE_TORQUE_SENSORS__STRUCT_HPP_

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
// Member 'l_foot'
// Member 'r_foot'
// Member 'l_hand'
// Member 'r_hand'
#include "geometry_msgs/msg/detail/wrench__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pronto_msgs__msg__BipedForceTorqueSensors __attribute__((deprecated))
#else
# define DEPRECATED__pronto_msgs__msg__BipedForceTorqueSensors __declspec(deprecated)
#endif

namespace pronto_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BipedForceTorqueSensors_
{
  using Type = BipedForceTorqueSensors_<ContainerAllocator>;

  explicit BipedForceTorqueSensors_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    l_foot(_init),
    r_foot(_init),
    l_hand(_init),
    r_hand(_init)
  {
    (void)_init;
  }

  explicit BipedForceTorqueSensors_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    l_foot(_alloc, _init),
    r_foot(_alloc, _init),
    l_hand(_alloc, _init),
    r_hand(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _l_foot_type =
    geometry_msgs::msg::Wrench_<ContainerAllocator>;
  _l_foot_type l_foot;
  using _r_foot_type =
    geometry_msgs::msg::Wrench_<ContainerAllocator>;
  _r_foot_type r_foot;
  using _l_hand_type =
    geometry_msgs::msg::Wrench_<ContainerAllocator>;
  _l_hand_type l_hand;
  using _r_hand_type =
    geometry_msgs::msg::Wrench_<ContainerAllocator>;
  _r_hand_type r_hand;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__l_foot(
    const geometry_msgs::msg::Wrench_<ContainerAllocator> & _arg)
  {
    this->l_foot = _arg;
    return *this;
  }
  Type & set__r_foot(
    const geometry_msgs::msg::Wrench_<ContainerAllocator> & _arg)
  {
    this->r_foot = _arg;
    return *this;
  }
  Type & set__l_hand(
    const geometry_msgs::msg::Wrench_<ContainerAllocator> & _arg)
  {
    this->l_hand = _arg;
    return *this;
  }
  Type & set__r_hand(
    const geometry_msgs::msg::Wrench_<ContainerAllocator> & _arg)
  {
    this->r_hand = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pronto_msgs::msg::BipedForceTorqueSensors_<ContainerAllocator> *;
  using ConstRawPtr =
    const pronto_msgs::msg::BipedForceTorqueSensors_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pronto_msgs::msg::BipedForceTorqueSensors_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pronto_msgs::msg::BipedForceTorqueSensors_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::BipedForceTorqueSensors_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::BipedForceTorqueSensors_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::BipedForceTorqueSensors_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::BipedForceTorqueSensors_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pronto_msgs::msg::BipedForceTorqueSensors_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pronto_msgs::msg::BipedForceTorqueSensors_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pronto_msgs__msg__BipedForceTorqueSensors
    std::shared_ptr<pronto_msgs::msg::BipedForceTorqueSensors_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pronto_msgs__msg__BipedForceTorqueSensors
    std::shared_ptr<pronto_msgs::msg::BipedForceTorqueSensors_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BipedForceTorqueSensors_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->l_foot != other.l_foot) {
      return false;
    }
    if (this->r_foot != other.r_foot) {
      return false;
    }
    if (this->l_hand != other.l_hand) {
      return false;
    }
    if (this->r_hand != other.r_hand) {
      return false;
    }
    return true;
  }
  bool operator!=(const BipedForceTorqueSensors_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BipedForceTorqueSensors_

// alias to use template instance with default allocator
using BipedForceTorqueSensors =
  pronto_msgs::msg::BipedForceTorqueSensors_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__BIPED_FORCE_TORQUE_SENSORS__STRUCT_HPP_
