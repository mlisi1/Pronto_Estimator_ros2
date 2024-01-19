// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pronto_msgs:msg/LidarOdometryUpdate.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pronto_msgs/msg/detail/lidar_odometry_update__rosidl_typesupport_introspection_c.h"
#include "pronto_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pronto_msgs/msg/detail/lidar_odometry_update__functions.h"
#include "pronto_msgs/msg/detail/lidar_odometry_update__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `curr_timestamp`
// Member `prev_timestamp`
#include "builtin_interfaces/msg/time.h"
// Member `curr_timestamp`
// Member `prev_timestamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `relative_transform`
#include "geometry_msgs/msg/transform.h"
// Member `relative_transform`
#include "geometry_msgs/msg/detail/transform__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pronto_msgs__msg__LidarOdometryUpdate__init(message_memory);
}

void pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_fini_function(void * message_memory)
{
  pronto_msgs__msg__LidarOdometryUpdate__fini(message_memory);
}

size_t pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__size_function__LidarOdometryUpdate__covariance(
  const void * untyped_member)
{
  (void)untyped_member;
  return 36;
}

const void * pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__get_const_function__LidarOdometryUpdate__covariance(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__get_function__LidarOdometryUpdate__covariance(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__fetch_function__LidarOdometryUpdate__covariance(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__get_const_function__LidarOdometryUpdate__covariance(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__assign_function__LidarOdometryUpdate__covariance(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__get_function__LidarOdometryUpdate__covariance(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__LidarOdometryUpdate, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "curr_timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__LidarOdometryUpdate, curr_timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "prev_timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__LidarOdometryUpdate, prev_timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "relative_transform",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__LidarOdometryUpdate, relative_transform),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "covariance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    36,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__LidarOdometryUpdate, covariance),  // bytes offset in struct
    NULL,  // default value
    pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__size_function__LidarOdometryUpdate__covariance,  // size() function pointer
    pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__get_const_function__LidarOdometryUpdate__covariance,  // get_const(index) function pointer
    pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__get_function__LidarOdometryUpdate__covariance,  // get(index) function pointer
    pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__fetch_function__LidarOdometryUpdate__covariance,  // fetch(index, &value) function pointer
    pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__assign_function__LidarOdometryUpdate__covariance,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_message_members = {
  "pronto_msgs__msg",  // message namespace
  "LidarOdometryUpdate",  // message name
  5,  // number of fields
  sizeof(pronto_msgs__msg__LidarOdometryUpdate),
  pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_message_member_array,  // message members
  pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_init_function,  // function to initialize message memory (memory has to be allocated)
  pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_message_type_support_handle = {
  0,
  &pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pronto_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pronto_msgs, msg, LidarOdometryUpdate)() {
  pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Transform)();
  if (!pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_message_type_support_handle.typesupport_identifier) {
    pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pronto_msgs__msg__LidarOdometryUpdate__rosidl_typesupport_introspection_c__LidarOdometryUpdate_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
