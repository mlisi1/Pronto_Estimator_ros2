// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pronto_msgs:msg/FilterState.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__FILTER_STATE__STRUCT_H_
#define PRONTO_MSGS__MSG__DETAIL__FILTER_STATE__STRUCT_H_

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
// Member 'quat'
#include "geometry_msgs/msg/detail/quaternion__struct.h"
// Member 'state'
// Member 'cov'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/FilterState in the package pronto_msgs.
typedef struct pronto_msgs__msg__FilterState
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Quaternion quat;
  rosidl_runtime_c__double__Sequence state;
  rosidl_runtime_c__double__Sequence cov;
} pronto_msgs__msg__FilterState;

// Struct for a sequence of pronto_msgs__msg__FilterState.
typedef struct pronto_msgs__msg__FilterState__Sequence
{
  pronto_msgs__msg__FilterState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pronto_msgs__msg__FilterState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRONTO_MSGS__MSG__DETAIL__FILTER_STATE__STRUCT_H_
