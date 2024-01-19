// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pronto_msgs:msg/FilterState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pronto_msgs/msg/detail/filter_state__rosidl_typesupport_introspection_c.h"
#include "pronto_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pronto_msgs/msg/detail/filter_state__functions.h"
#include "pronto_msgs/msg/detail/filter_state__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `quat`
#include "geometry_msgs/msg/quaternion.h"
// Member `quat`
#include "geometry_msgs/msg/detail/quaternion__rosidl_typesupport_introspection_c.h"
// Member `state`
// Member `cov`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__FilterState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pronto_msgs__msg__FilterState__init(message_memory);
}

void pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__FilterState_fini_function(void * message_memory)
{
  pronto_msgs__msg__FilterState__fini(message_memory);
}

size_t pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__size_function__FilterState__state(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__get_const_function__FilterState__state(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__get_function__FilterState__state(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__fetch_function__FilterState__state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__get_const_function__FilterState__state(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__assign_function__FilterState__state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__get_function__FilterState__state(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__resize_function__FilterState__state(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__size_function__FilterState__cov(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__get_const_function__FilterState__cov(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__get_function__FilterState__cov(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__fetch_function__FilterState__cov(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__get_const_function__FilterState__cov(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__assign_function__FilterState__cov(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__get_function__FilterState__cov(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__resize_function__FilterState__cov(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__FilterState_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__FilterState, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "quat",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__FilterState, quat),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__FilterState, state),  // bytes offset in struct
    NULL,  // default value
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__size_function__FilterState__state,  // size() function pointer
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__get_const_function__FilterState__state,  // get_const(index) function pointer
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__get_function__FilterState__state,  // get(index) function pointer
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__fetch_function__FilterState__state,  // fetch(index, &value) function pointer
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__assign_function__FilterState__state,  // assign(index, value) function pointer
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__resize_function__FilterState__state  // resize(index) function pointer
  },
  {
    "cov",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__FilterState, cov),  // bytes offset in struct
    NULL,  // default value
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__size_function__FilterState__cov,  // size() function pointer
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__get_const_function__FilterState__cov,  // get_const(index) function pointer
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__get_function__FilterState__cov,  // get(index) function pointer
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__fetch_function__FilterState__cov,  // fetch(index, &value) function pointer
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__assign_function__FilterState__cov,  // assign(index, value) function pointer
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__resize_function__FilterState__cov  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__FilterState_message_members = {
  "pronto_msgs__msg",  // message namespace
  "FilterState",  // message name
  4,  // number of fields
  sizeof(pronto_msgs__msg__FilterState),
  pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__FilterState_message_member_array,  // message members
  pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__FilterState_init_function,  // function to initialize message memory (memory has to be allocated)
  pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__FilterState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__FilterState_message_type_support_handle = {
  0,
  &pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__FilterState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pronto_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pronto_msgs, msg, FilterState)() {
  pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__FilterState_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__FilterState_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Quaternion)();
  if (!pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__FilterState_message_type_support_handle.typesupport_identifier) {
    pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__FilterState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pronto_msgs__msg__FilterState__rosidl_typesupport_introspection_c__FilterState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
