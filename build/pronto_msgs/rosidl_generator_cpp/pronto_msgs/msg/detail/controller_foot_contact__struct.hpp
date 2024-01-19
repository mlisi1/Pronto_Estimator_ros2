// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pronto_msgs:msg/ControllerFootContact.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__CONTROLLER_FOOT_CONTACT__STRUCT_HPP_
#define PRONTO_MSGS__MSG__DETAIL__CONTROLLER_FOOT_CONTACT__STRUCT_HPP_

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
# define DEPRECATED__pronto_msgs__msg__ControllerFootContact __attribute__((deprecated))
#else
# define DEPRECATED__pronto_msgs__msg__ControllerFootContact __declspec(deprecated)
#endif

namespace pronto_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ControllerFootContact_
{
  using Type = ControllerFootContact_<ContainerAllocator>;

  explicit ControllerFootContact_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num_right_foot_contacts = 0l;
      this->num_left_foot_contacts = 0l;
    }
  }

  explicit ControllerFootContact_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num_right_foot_contacts = 0l;
      this->num_left_foot_contacts = 0l;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _num_right_foot_contacts_type =
    int32_t;
  _num_right_foot_contacts_type num_right_foot_contacts;
  using _right_foot_contacts_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _right_foot_contacts_type right_foot_contacts;
  using _num_left_foot_contacts_type =
    int32_t;
  _num_left_foot_contacts_type num_left_foot_contacts;
  using _left_foot_contacts_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _left_foot_contacts_type left_foot_contacts;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__num_right_foot_contacts(
    const int32_t & _arg)
  {
    this->num_right_foot_contacts = _arg;
    return *this;
  }
  Type & set__right_foot_contacts(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->right_foot_contacts = _arg;
    return *this;
  }
  Type & set__num_left_foot_contacts(
    const int32_t & _arg)
  {
    this->num_left_foot_contacts = _arg;
    return *this;
  }
  Type & set__left_foot_contacts(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->left_foot_contacts = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pronto_msgs::msg::ControllerFootContact_<ContainerAllocator> *;
  using ConstRawPtr =
    const pronto_msgs::msg::ControllerFootContact_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pronto_msgs::msg::ControllerFootContact_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pronto_msgs::msg::ControllerFootContact_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::ControllerFootContact_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::ControllerFootContact_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pronto_msgs::msg::ControllerFootContact_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pronto_msgs::msg::ControllerFootContact_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pronto_msgs::msg::ControllerFootContact_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pronto_msgs::msg::ControllerFootContact_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pronto_msgs__msg__ControllerFootContact
    std::shared_ptr<pronto_msgs::msg::ControllerFootContact_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pronto_msgs__msg__ControllerFootContact
    std::shared_ptr<pronto_msgs::msg::ControllerFootContact_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ControllerFootContact_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->num_right_foot_contacts != other.num_right_foot_contacts) {
      return false;
    }
    if (this->right_foot_contacts != other.right_foot_contacts) {
      return false;
    }
    if (this->num_left_foot_contacts != other.num_left_foot_contacts) {
      return false;
    }
    if (this->left_foot_contacts != other.left_foot_contacts) {
      return false;
    }
    return true;
  }
  bool operator!=(const ControllerFootContact_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ControllerFootContact_

// alias to use template instance with default allocator
using ControllerFootContact =
  pronto_msgs::msg::ControllerFootContact_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pronto_msgs

#endif  // PRONTO_MSGS__MSG__DETAIL__CONTROLLER_FOOT_CONTACT__STRUCT_HPP_
