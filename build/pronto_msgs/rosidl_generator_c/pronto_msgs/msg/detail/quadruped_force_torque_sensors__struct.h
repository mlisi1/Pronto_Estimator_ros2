// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pronto_msgs:msg/QuadrupedForceTorqueSensors.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__QUADRUPED_FORCE_TORQUE_SENSORS__STRUCT_H_
#define PRONTO_MSGS__MSG__DETAIL__QUADRUPED_FORCE_TORQUE_SENSORS__STRUCT_H_

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
// Member 'lf'
// Member 'rf'
// Member 'lh'
// Member 'rh'
#include "geometry_msgs/msg/detail/wrench__struct.h"

/// Struct defined in msg/QuadrupedForceTorqueSensors in the package pronto_msgs.
/**
  * Atlas force torque sensors for the wrists and ankles
 */
typedef struct pronto_msgs__msg__QuadrupedForceTorqueSensors
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Wrench lf;
  geometry_msgs__msg__Wrench rf;
  geometry_msgs__msg__Wrench lh;
  geometry_msgs__msg__Wrench rh;
} pronto_msgs__msg__QuadrupedForceTorqueSensors;

// Struct for a sequence of pronto_msgs__msg__QuadrupedForceTorqueSensors.
typedef struct pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence
{
  pronto_msgs__msg__QuadrupedForceTorqueSensors * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRONTO_MSGS__MSG__DETAIL__QUADRUPED_FORCE_TORQUE_SENSORS__STRUCT_H_
