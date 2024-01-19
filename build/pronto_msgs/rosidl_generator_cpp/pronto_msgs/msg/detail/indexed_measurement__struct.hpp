// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pronto_msgs:msg/IndexedMeasurement.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__INDEXED_MEASUREMENT__STRUCT_HPP_
#define PRONTO_MSGS__MSG__DETAIL__INDEXED_MEASUREMENT__STRUCT_HPP_

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
# define DEPRECATED__pronto_msgs__msg__IndexedMeasurement __attribute__((deprecated))
#else
# define DEPRECATED__pronto_msgs__msg__IndexedMeasurement __declspec(deprecated)
#endif

namespace pronto_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IndexedMeasurement_
{
  using Type = IndexedMeasurement_<ContainerAllocator>;

  explicit IndexedMeasurement_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->utime = 0ull;
      this->state_utime = 0ull;
    }
  }

  explicit IndexedMeasurement_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->utime = 0ull;
      this->state_utime = 0ull;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _utime_type =
    uint64_t;
  _utime_type utime;
  using _state_utime_type =
    uint64_t;
  _state_utime_type state_utime;
  using _z_effective_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _z_effective_type z_effective;
  using _z_indices_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _z_indices_type z_indices;
  using _r_effective_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _r_effective_type r_effective;

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
  Type & set__state_utime(
    const uint64_t & _arg)
  {
    this->state_utime = _arg;
    return *this;
  }
  Type & set__z_effective(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->z_effective = _arg;
    return *this;
  }
  Type & set__z_indices(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->z_indices = _arg;
    return *this;
  }
  Type & set__r_effective(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->r_effective = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pronto_msgs::msg::IndexedMeasurement_<ContainerAllocator> *;
  using ConstRawPtr =
    const pronto_msgs::msg::IndexedMeasurement_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pronto_msgs::msg::IndexedMeasurement_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pronto_msgs::msg::IndexedMeasurement_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::IndexedMeasurement_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::IndexedMeasurement_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::IndexedMeasurement_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::IndexedMeasurement_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pronto_msgs::msg::IndexedMeasurement_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pronto_msgs::msg::IndexedMeasurement_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pronto_msgs__msg__IndexedMeasurement
    std::shared_ptr<pronto_msgs::msg::IndexedMeasurement_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pronto_msgs__msg__IndexedMeasurement
    std::shared_ptr<pronto_msgs::msg::IndexedMeasurement_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IndexedMeasurement_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->utime != other.utime) {
      return false;
    }
    if (this->state_utime != other.state_utime) {
      return false;
    }
    if (this->z_effective != other.z_effective) {
      return false;
    }
    if (this->z_indices != other.z_indices) {
      return false;
    }
    if (this->r_effective != other.r_effective) {
      return false;
    }
    return true;
  }
  bool operator!=(const IndexedMeasurement_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IndexedMeasurement_

// alias to use template instance with default allocator
using IndexedMeasurement =
  pronto_msgs::msg::IndexedMeasurement_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__INDEXED_MEASUREMENT__STRUCT_HPP_
