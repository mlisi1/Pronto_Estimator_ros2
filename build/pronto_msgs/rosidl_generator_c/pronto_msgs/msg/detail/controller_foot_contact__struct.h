// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pronto_msgs:msg/ControllerFootContact.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__CONTROLLER_FOOT_CONTACT__STRUCT_H_
#define PRONTO_MSGS__MSG__DETAIL__CONTROLLER_FOOT_CONTACT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'right_foot_contacts'
// Member 'left_foot_contacts'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/ControllerFootContact in the package pronto_msgs.
typedef struct pronto_msgs__msg__ControllerFootContact
{
  std_msgs__msg__Header header;
  int32_t num_right_foot_contacts;
  /// Porting from LCM definition:
  /// double right_foot_contacts[3][num_right_foot_contacts]
  rosidl_runtime_c__double__Sequence right_foot_contacts;
  int32_t num_left_foot_contacts;
  /// Porting from LCM definition:
  /// double left_foot_contacts[3][num_left_foot_contacts];
  rosidl_runtime_c__double__Sequence left_foot_contacts;
} pronto_msgs__msg__ControllerFootContact;

// Struct for a sequence of pronto_msgs__msg__ControllerFootContact.
typedef struct pronto_msgs__msg__ControllerFootContact__Sequence
{
  pronto_msgs__msg__ControllerFootContact * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pronto_msgs__msg__ControllerFootContact__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRONTO_MSGS__MSG__DETAIL__CONTROLLER_FOOT_CONTACT__STRUCT_H_
