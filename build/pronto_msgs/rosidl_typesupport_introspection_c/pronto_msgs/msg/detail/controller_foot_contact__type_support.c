// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pronto_msgs:msg/ControllerFootContact.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pronto_msgs/msg/detail/controller_foot_contact__rosidl_typesupport_introspection_c.h"
#include "pronto_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pronto_msgs/msg/detail/controller_foot_contact__functions.h"
#include "pronto_msgs/msg/detail/controller_foot_contact__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `right_foot_contacts`
// Member `left_foot_contacts`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__ControllerFootContact_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pronto_msgs__msg__ControllerFootContact__init(message_memory);
}

void pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__ControllerFootContact_fini_function(void * message_memory)
{
  pronto_msgs__msg__ControllerFootContact__fini(message_memory);
}

size_t pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__size_function__ControllerFootContact__right_foot_contacts(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__get_const_function__ControllerFootContact__right_foot_contacts(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__get_function__ControllerFootContact__right_foot_contacts(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__fetch_function__ControllerFootContact__right_foot_contacts(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__get_const_function__ControllerFootContact__right_foot_contacts(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__assign_function__ControllerFootContact__right_foot_contacts(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__get_function__ControllerFootContact__right_foot_contacts(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__resize_function__ControllerFootContact__right_foot_contacts(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__size_function__ControllerFootContact__left_foot_contacts(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__get_const_function__ControllerFootContact__left_foot_contacts(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__get_function__ControllerFootContact__left_foot_contacts(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__fetch_function__ControllerFootContact__left_foot_contacts(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__get_const_function__ControllerFootContact__left_foot_contacts(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__assign_function__ControllerFootContact__left_foot_contacts(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__get_function__ControllerFootContact__left_foot_contacts(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__resize_function__ControllerFootContact__left_foot_contacts(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__ControllerFootContact_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__ControllerFootContact, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_right_foot_contacts",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__ControllerFootContact, num_right_foot_contacts),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "right_foot_contacts",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__ControllerFootContact, right_foot_contacts),  // bytes offset in struct
    NULL,  // default value
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__size_function__ControllerFootContact__right_foot_contacts,  // size() function pointer
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__get_const_function__ControllerFootContact__right_foot_contacts,  // get_const(index) function pointer
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__get_function__ControllerFootContact__right_foot_contacts,  // get(index) function pointer
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__fetch_function__ControllerFootContact__right_foot_contacts,  // fetch(index, &value) function pointer
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__assign_function__ControllerFootContact__right_foot_contacts,  // assign(index, value) function pointer
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__resize_function__ControllerFootContact__right_foot_contacts  // resize(index) function pointer
  },
  {
    "num_left_foot_contacts",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__ControllerFootContact, num_left_foot_contacts),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "left_foot_contacts",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__ControllerFootContact, left_foot_contacts),  // bytes offset in struct
    NULL,  // default value
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__size_function__ControllerFootContact__left_foot_contacts,  // size() function pointer
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__get_const_function__ControllerFootContact__left_foot_contacts,  // get_const(index) function pointer
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__get_function__ControllerFootContact__left_foot_contacts,  // get(index) function pointer
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__fetch_function__ControllerFootContact__left_foot_contacts,  // fetch(index, &value) function pointer
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__assign_function__ControllerFootContact__left_foot_contacts,  // assign(index, value) function pointer
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__resize_function__ControllerFootContact__left_foot_contacts  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__ControllerFootContact_message_members = {
  "pronto_msgs__msg",  // message namespace
  "ControllerFootContact",  // message name
  5,  // number of fields
  sizeof(pronto_msgs__msg__ControllerFootContact),
  pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__ControllerFootContact_message_member_array,  // message members
  pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__ControllerFootContact_init_function,  // function to initialize message memory (memory has to be allocated)
  pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__ControllerFootContact_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__ControllerFootContact_message_type_support_handle = {
  0,
  &pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__ControllerFootContact_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pronto_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pronto_msgs, msg, ControllerFootContact)() {
  pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__ControllerFootContact_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__ControllerFootContact_message_type_support_handle.typesupport_identifier) {
    pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__ControllerFootContact_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pronto_msgs__msg__ControllerFootContact__rosidl_typesupport_introspection_c__ControllerFootContact_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
