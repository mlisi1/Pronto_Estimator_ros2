// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pronto_msgs:msg/QuadrupedStance.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__QUADRUPED_STANCE__STRUCT_HPP_
#define PRONTO_MSGS__MSG__DETAIL__QUADRUPED_STANCE__STRUCT_HPP_

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
# define DEPRECATED__pronto_msgs__msg__QuadrupedStance __attribute__((deprecated))
#else
# define DEPRECATED__pronto_msgs__msg__QuadrupedStance __declspec(deprecated)
#endif

namespace pronto_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct QuadrupedStance_
{
  using Type = QuadrupedStance_<ContainerAllocator>;

  explicit QuadrupedStance_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lf = 0.0f;
      this->rf = 0.0f;
      this->lh = 0.0f;
      this->rh = 0.0f;
    }
  }

  explicit QuadrupedStance_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lf = 0.0f;
      this->rf = 0.0f;
      this->lh = 0.0f;
      this->rh = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _lf_type =
    float;
  _lf_type lf;
  using _rf_type =
    float;
  _rf_type rf;
  using _lh_type =
    float;
  _lh_type lh;
  using _rh_type =
    float;
  _rh_type rh;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__lf(
    const float & _arg)
  {
    this->lf = _arg;
    return *this;
  }
  Type & set__rf(
    const float & _arg)
  {
    this->rf = _arg;
    return *this;
  }
  Type & set__lh(
    const float & _arg)
  {
    this->lh = _arg;
    return *this;
  }
  Type & set__rh(
    const float & _arg)
  {
    this->rh = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pronto_msgs::msg::QuadrupedStance_<ContainerAllocator> *;
  using ConstRawPtr =
    const pronto_msgs::msg::QuadrupedStance_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pronto_msgs::msg::QuadrupedStance_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pronto_msgs::msg::QuadrupedStance_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::QuadrupedStance_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::QuadrupedStance_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::QuadrupedStance_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::QuadrupedStance_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pronto_msgs::msg::QuadrupedStance_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pronto_msgs::msg::QuadrupedStance_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pronto_msgs__msg__QuadrupedStance
    std::shared_ptr<pronto_msgs::msg::QuadrupedStance_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pronto_msgs__msg__QuadrupedStance
    std::shared_ptr<pronto_msgs::msg::QuadrupedStance_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const QuadrupedStance_ & other) const
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
  bool operator!=(const QuadrupedStance_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct QuadrupedStance_

// alias to use template instance with default allocator
using QuadrupedStance =
  pronto_msgs::msg::QuadrupedStance_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__QUADRUPED_STANCE__STRUCT_HPP_
