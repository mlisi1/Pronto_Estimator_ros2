// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pronto_msgs:msg/QuadrupedStance.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__QUADRUPED_STANCE__STRUCT_H_
#define PRONTO_MSGS__MSG__DETAIL__QUADRUPED_STANCE__STRUCT_H_

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

/// Struct defined in msg/QuadrupedStance in the package pronto_msgs.
typedef struct pronto_msgs__msg__QuadrupedStance
{
  std_msgs__msg__Header header;
  float lf;
  float rf;
  float lh;
  float rh;
} pronto_msgs__msg__QuadrupedStance;

// Struct for a sequence of pronto_msgs__msg__QuadrupedStance.
typedef struct pronto_msgs__msg__QuadrupedStance__Sequence
{
  pronto_msgs__msg__QuadrupedStance * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pronto_msgs__msg__QuadrupedStance__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRONTO_MSGS__MSG__DETAIL__QUADRUPED_STANCE__STRUCT_H_
