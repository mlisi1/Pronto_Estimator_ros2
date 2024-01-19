// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pronto_msgs:msg/IndexedMeasurement.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__INDEXED_MEASUREMENT__STRUCT_H_
#define PRONTO_MSGS__MSG__DETAIL__INDEXED_MEASUREMENT__STRUCT_H_

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
// Member 'z_effective'
// Member 'z_indices'
// Member 'r_effective'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/IndexedMeasurement in the package pronto_msgs.
typedef struct pronto_msgs__msg__IndexedMeasurement
{
  std_msgs__msg__Header header;
  uint64_t utime;
  uint64_t state_utime;
  rosidl_runtime_c__double__Sequence z_effective;
  rosidl_runtime_c__int32__Sequence z_indices;
  rosidl_runtime_c__double__Sequence r_effective;
} pronto_msgs__msg__IndexedMeasurement;

// Struct for a sequence of pronto_msgs__msg__IndexedMeasurement.
typedef struct pronto_msgs__msg__IndexedMeasurement__Sequence
{
  pronto_msgs__msg__IndexedMeasurement * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pronto_msgs__msg__IndexedMeasurement__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRONTO_MSGS__MSG__DETAIL__INDEXED_MEASUREMENT__STRUCT_H_
