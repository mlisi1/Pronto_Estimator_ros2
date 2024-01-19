// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pronto_msgs:msg/FilterState.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__FILTER_STATE__STRUCT_HPP_
#define PRONTO_MSGS__MSG__DETAIL__FILTER_STATE__STRUCT_HPP_

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
// Member 'quat'
#include "geometry_msgs/msg/detail/quaternion__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pronto_msgs__msg__FilterState __attribute__((deprecated))
#else
# define DEPRECATED__pronto_msgs__msg__FilterState __declspec(deprecated)
#endif

namespace pronto_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FilterState_
{
  using Type = FilterState_<ContainerAllocator>;

  explicit FilterState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    quat(_init)
  {
    (void)_init;
  }

  explicit FilterState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    quat(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _quat_type =
    geometry_msgs::msg::Quaternion_<ContainerAllocator>;
  _quat_type quat;
  using _state_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _state_type state;
  using _cov_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _cov_type cov;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__quat(
    const geometry_msgs::msg::Quaternion_<ContainerAllocator> & _arg)
  {
    this->quat = _arg;
    return *this;
  }
  Type & set__state(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__cov(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->cov = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pronto_msgs::msg::FilterState_<ContainerAllocator> *;
  using ConstRawPtr =
    const pronto_msgs::msg::FilterState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pronto_msgs::msg::FilterState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pronto_msgs::msg::FilterState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::FilterState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::FilterState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::FilterState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::FilterState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pronto_msgs::msg::FilterState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pronto_msgs::msg::FilterState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pronto_msgs__msg__FilterState
    std::shared_ptr<pronto_msgs::msg::FilterState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pronto_msgs__msg__FilterState
    std::shared_ptr<pronto_msgs::msg::FilterState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FilterState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->quat != other.quat) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    if (this->cov != other.cov) {
      return false;
    }
    return true;
  }
  bool operator!=(const FilterState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FilterState_

// alias to use template instance with default allocator
using FilterState =
  pronto_msgs::msg::FilterState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__FILTER_STATE__STRUCT_HPP_
