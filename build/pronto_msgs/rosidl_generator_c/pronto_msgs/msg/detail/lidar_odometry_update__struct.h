// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pronto_msgs:msg/LidarOdometryUpdate.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__LIDAR_ODOMETRY_UPDATE__STRUCT_H_
#define PRONTO_MSGS__MSG__DETAIL__LIDAR_ODOMETRY_UPDATE__STRUCT_H_

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
// Member 'curr_timestamp'
// Member 'prev_timestamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'relative_transform'
#include "geometry_msgs/msg/detail/transform__struct.h"

/// Struct defined in msg/LidarOdometryUpdate in the package pronto_msgs.
typedef struct pronto_msgs__msg__LidarOdometryUpdate
{
  std_msgs__msg__Header header;
  /// TODO: check if these definitions are correct
  builtin_interfaces__msg__Time curr_timestamp;
  builtin_interfaces__msg__Time prev_timestamp;
  geometry_msgs__msg__Transform relative_transform;
  double covariance[36];
} pronto_msgs__msg__LidarOdometryUpdate;

// Struct for a sequence of pronto_msgs__msg__LidarOdometryUpdate.
typedef struct pronto_msgs__msg__LidarOdometryUpdate__Sequence
{
  pronto_msgs__msg__LidarOdometryUpdate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pronto_msgs__msg__LidarOdometryUpdate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PRONTO_MSGS__MSG__DETAIL__LIDAR_ODOMETRY_UPDATE__STRUCT_H_
