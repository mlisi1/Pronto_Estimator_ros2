// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pronto_msgs:msg/VelocityWithSigmaBounds.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__STRUCT_H_
#define PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__STRUCT_H_

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
// Member 'velocity_plus_one_sigma'
// Member 'velocity_minus_one_sigma'
// Member 'plus_one_sigma'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/VelocityWithSigmaBounds in the package pronto_msgs.
/**
  * convenience message encoding the linear velocity
  * one sigma bounds (plus, minus) and the sigma alone
 */
typedef struct pronto_msgs__msg__VelocityWithSigmaBounds
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Vector3 velocity_plus_one_sigma;
  geometry_msgs__msg__Vector3 velocity_minus_one_sigma;
  geometry_msgs__msg__Vector3 plus_one_sigma;
} pronto_msgs__msg__VelocityWithSigmaBounds;

// Struct for a sequence of pronto_msgs__msg__VelocityWithSigmaBounds.
typedef struct pronto_msgs__msg__VelocityWithSigmaBounds__Sequence
{
  pronto_msgs__msg__VelocityWithSigmaBounds * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pronto_msgs__msg__VelocityWithSigmaBounds__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__STRUCT_H_
