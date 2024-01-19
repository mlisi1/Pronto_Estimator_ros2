// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from pronto_msgs:msg/IndexedMeasurement.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "pronto_msgs/msg/detail/indexed_measurement__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace pronto_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void IndexedMeasurement_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) pronto_msgs::msg::IndexedMeasurement(_init);
}

void IndexedMeasurement_fini_function(void * message_memory)
{
  auto typed_message = static_cast<pronto_msgs::msg::IndexedMeasurement *>(message_memory);
  typed_message->~IndexedMeasurement();
}

size_t size_function__IndexedMeasurement__z_effective(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__IndexedMeasurement__z_effective(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__IndexedMeasurement__z_effective(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__IndexedMeasurement__z_effective(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__IndexedMeasurement__z_effective(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__IndexedMeasurement__z_effective(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__IndexedMeasurement__z_effective(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__IndexedMeasurement__z_effective(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__IndexedMeasurement__z_indices(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__IndexedMeasurement__z_indices(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void * get_function__IndexedMeasurement__z_indices(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__IndexedMeasurement__z_indices(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__IndexedMeasurement__z_indices(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__IndexedMeasurement__z_indices(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__IndexedMeasurement__z_indices(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

void resize_function__IndexedMeasurement__z_indices(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int32_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__IndexedMeasurement__r_effective(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__IndexedMeasurement__r_effective(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__IndexedMeasurement__r_effective(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__IndexedMeasurement__r_effective(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__IndexedMeasurement__r_effective(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__IndexedMeasurement__r_effective(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__IndexedMeasurement__r_effective(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__IndexedMeasurement__r_effective(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember IndexedMeasurement_message_member_array[6] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs::msg::IndexedMeasurement, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "utime",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs::msg::IndexedMeasurement, utime),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "state_utime",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs::msg::IndexedMeasurement, state_utime),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "z_effective",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs::msg::IndexedMeasurement, z_effective),  // bytes offset in struct
    nullptr,  // default value
    size_function__IndexedMeasurement__z_effective,  // size() function pointer
    get_const_function__IndexedMeasurement__z_effective,  // get_const(index) function pointer
    get_function__IndexedMeasurement__z_effective,  // get(index) function pointer
    fetch_function__IndexedMeasurement__z_effective,  // fetch(index, &value) function pointer
    assign_function__IndexedMeasurement__z_effective,  // assign(index, value) function pointer
    resize_function__IndexedMeasurement__z_effective  // resize(index) function pointer
  },
  {
    "z_indices",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs::msg::IndexedMeasurement, z_indices),  // bytes offset in struct
    nullptr,  // default value
    size_function__IndexedMeasurement__z_indices,  // size() function pointer
    get_const_function__IndexedMeasurement__z_indices,  // get_const(index) function pointer
    get_function__IndexedMeasurement__z_indices,  // get(index) function pointer
    fetch_function__IndexedMeasurement__z_indices,  // fetch(index, &value) function pointer
    assign_function__IndexedMeasurement__z_indices,  // assign(index, value) function pointer
    resize_function__IndexedMeasurement__z_indices  // resize(index) function pointer
  },
  {
    "r_effective",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs::msg::IndexedMeasurement, r_effective),  // bytes offset in struct
    nullptr,  // default value
    size_function__IndexedMeasurement__r_effective,  // size() function pointer
    get_const_function__IndexedMeasurement__r_effective,  // get_const(index) function pointer
    get_function__IndexedMeasurement__r_effective,  // get(index) function pointer
    fetch_function__IndexedMeasurement__r_effective,  // fetch(index, &value) function pointer
    assign_function__IndexedMeasurement__r_effective,  // assign(index, value) function pointer
    resize_function__IndexedMeasurement__r_effective  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers IndexedMeasurement_message_members = {
  "pronto_msgs::msg",  // message namespace
  "IndexedMeasurement",  // message name
  6,  // number of fields
  sizeof(pronto_msgs::msg::IndexedMeasurement),
  IndexedMeasurement_message_member_array,  // message members
  IndexedMeasurement_init_function,  // function to initialize message memory (memory has to be allocated)
  IndexedMeasurement_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t IndexedMeasurement_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &IndexedMeasurement_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace pronto_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<pronto_msgs::msg::IndexedMeasurement>()
{
  return &::pronto_msgs::msg::rosidl_typesupport_introspection_cpp::IndexedMeasurement_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, pronto_msgs, msg, IndexedMeasurement)() {
  return &::pronto_msgs::msg::rosidl_typesupport_introspection_cpp::IndexedMeasurement_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
