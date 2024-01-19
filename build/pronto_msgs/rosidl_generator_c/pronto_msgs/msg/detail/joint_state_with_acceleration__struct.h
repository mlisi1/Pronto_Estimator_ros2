// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pronto_msgs:msg/JointStateWithAcceleration.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__JOINT_STATE_WITH_ACCELERATION__STRUCT_H_
#define PRONTO_MSGS__MSG__DETAIL__JOINT_STATE_WITH_ACCELERATION__STRUCT_H_

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
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'position'
// Member 'velocity'
// Member 'acceleration'
// Member 'effort'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/JointStateWithAcceleration in the package pronto_msgs.
/**
  *  This is a message that holds data to describe the state of a set of torque controlled joints. 
  *
  *  The state of each joint (revolute or prismatic) is defined by:
  *   * the position of the joint (rad or m),
  *   * the velocity of the joint (rad/s or m/s),
  *   * the acceleration of the joint (rad/s^2 or m/s^2), and
  *   * the effort that is applied in the joint (Nm or N).
  *
  *  Each joint is uniquely identified by its name
  *  The header specifies the time at which the joint states were recorded. All the joint states
  *  in one message have to be recorded at the same time.
  *
  * ----------------------- Header has been replaced with Time ----------------------
  *
  *  This message consists of a multiple arrays, one for each part of the joint state. 
  *  The goal is to make each of the fields optional. When e.g. your joints have no
  *  effort associated with them, you can leave the effort array empty. 
  *
  *  All arrays in this message should have the same size, or be empty.
  *  This is the only way to uniquely associate the joint name with the correct
  *  states.
 */
typedef struct pronto_msgs__msg__JointStateWithAcceleration
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String__Sequence name;
  rosidl_runtime_c__double__Sequence position;
  rosidl_runtime_c__double__Sequence velocity;
  rosidl_runtime_c__double__Sequence acceleration;
  rosidl_runtime_c__double__Sequence effort;
} pronto_msgs__msg__JointStateWithAcceleration;

// Struct for a sequence of pronto_msgs__msg__JointStateWithAcceleration.
typedef struct pronto_msgs__msg__JointStateWithAcceleration__Sequence
{
  pronto_msgs__msg__JointStateWithAcceleration * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pronto_msgs__msg__JointStateWithAcceleration__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRONTO_MSGS__MSG__DETAIL__JOINT_STATE_WITH_ACCELERATION__STRUCT_H_
