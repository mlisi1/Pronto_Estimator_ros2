// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pronto_msgs:msg/VisualOdometryUpdate.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__VISUAL_ODOMETRY_UPDATE__STRUCT_H_
#define PRONTO_MSGS__MSG__DETAIL__VISUAL_ODOMETRY_UPDATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'NO_DATA'.
enum
{
  pronto_msgs__msg__VisualOdometryUpdate__NO_DATA = 0
};

/// Constant 'ESTIMATE_VALID'.
enum
{
  pronto_msgs__msg__VisualOdometryUpdate__ESTIMATE_VALID = 1
};

/// Constant 'ESTIMATE_INSUFFICIENT_FEATURES'.
enum
{
  pronto_msgs__msg__VisualOdometryUpdate__ESTIMATE_INSUFFICIENT_FEATURES = 2
};

/// Constant 'ESTIMATE_DEGENERATE'.
enum
{
  pronto_msgs__msg__VisualOdometryUpdate__ESTIMATE_DEGENERATE = 3
};

/// Constant 'ESTIMATE_REPROJECTION_ERROR'.
enum
{
  pronto_msgs__msg__VisualOdometryUpdate__ESTIMATE_REPROJECTION_ERROR = 4
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'curr_timestamp'
// Member 'prev_timestamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'relative_transform'
#include "geometry_msgs/msg/detail/transform__struct.h"

/// Struct defined in msg/VisualOdometryUpdate in the package pronto_msgs.
typedef struct pronto_msgs__msg__VisualOdometryUpdate
{
  std_msgs__msg__Header header;
  builtin_interfaces__msg__Time curr_timestamp;
  builtin_interfaces__msg__Time prev_timestamp;
  geometry_msgs__msg__Transform relative_transform;
  double covariance[36];
  uint8_t estimate_status;
} pronto_msgs__msg__VisualOdometryUpdate;

// Struct for a sequence of pronto_msgs__msg__VisualOdometryUpdate.
typedef struct pronto_msgs__msg__VisualOdometryUpdate__Sequence
{
  pronto_msgs__msg__VisualOdometryUpdate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pronto_msgs__msg__VisualOdometryUpdate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRONTO_MSGS__MSG__DETAIL__VISUAL_ODOMETRY_UPDATE__STRUCT_H_
