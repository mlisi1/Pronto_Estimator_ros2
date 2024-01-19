// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pronto_msgs:msg/VelocityWithSigmaBounds.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__STRUCT_HPP_
#define PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__STRUCT_HPP_

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
// Member 'velocity_plus_one_sigma'
// Member 'velocity_minus_one_sigma'
// Member 'plus_one_sigma'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pronto_msgs__msg__VelocityWithSigmaBounds __attribute__((deprecated))
#else
# define DEPRECATED__pronto_msgs__msg__VelocityWithSigmaBounds __declspec(deprecated)
#endif

namespace pronto_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VelocityWithSigmaBounds_
{
  using Type = VelocityWithSigmaBounds_<ContainerAllocator>;

  explicit VelocityWithSigmaBounds_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    velocity_plus_one_sigma(_init),
    velocity_minus_one_sigma(_init),
    plus_one_sigma(_init)
  {
    (void)_init;
  }

  explicit VelocityWithSigmaBounds_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    velocity_plus_one_sigma(_alloc, _init),
    velocity_minus_one_sigma(_alloc, _init),
    plus_one_sigma(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _velocity_plus_one_sigma_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _velocity_plus_one_sigma_type velocity_plus_one_sigma;
  using _velocity_minus_one_sigma_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _velocity_minus_one_sigma_type velocity_minus_one_sigma;
  using _plus_one_sigma_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _plus_one_sigma_type plus_one_sigma;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__velocity_plus_one_sigma(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->velocity_plus_one_sigma = _arg;
    return *this;
  }
  Type & set__velocity_minus_one_sigma(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->velocity_minus_one_sigma = _arg;
    return *this;
  }
  Type & set__plus_one_sigma(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->plus_one_sigma = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pronto_msgs::msg::VelocityWithSigmaBounds_<ContainerAllocator> *;
  using ConstRawPtr =
    const pronto_msgs::msg::VelocityWithSigmaBounds_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pronto_msgs::msg::VelocityWithSigmaBounds_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pronto_msgs::msg::VelocityWithSigmaBounds_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::VelocityWithSigmaBounds_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::VelocityWithSigmaBounds_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::VelocityWithSigmaBounds_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::VelocityWithSigmaBounds_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pronto_msgs::msg::VelocityWithSigmaBounds_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pronto_msgs::msg::VelocityWithSigmaBounds_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pronto_msgs__msg__VelocityWithSigmaBounds
    std::shared_ptr<pronto_msgs::msg::VelocityWithSigmaBounds_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pronto_msgs__msg__VelocityWithSigmaBounds
    std::shared_ptr<pronto_msgs::msg::VelocityWithSigmaBounds_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VelocityWithSigmaBounds_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->velocity_plus_one_sigma != other.velocity_plus_one_sigma) {
      return false;
    }
    if (this->velocity_minus_one_sigma != other.velocity_minus_one_sigma) {
      return false;
    }
    if (this->plus_one_sigma != other.plus_one_sigma) {
      return false;
    }
    return true;
  }
  bool operator!=(const VelocityWithSigmaBounds_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VelocityWithSigmaBounds_

// alias to use template instance with default allocator
using VelocityWithSigmaBounds =
  pronto_msgs::msg::VelocityWithSigmaBounds_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__STRUCT_HPP_
