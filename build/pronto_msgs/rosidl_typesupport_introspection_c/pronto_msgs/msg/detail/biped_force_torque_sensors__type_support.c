// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pronto_msgs:msg/BipedForceTorqueSensors.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pronto_msgs/msg/detail/biped_force_torque_sensors__rosidl_typesupport_introspection_c.h"
#include "pronto_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pronto_msgs/msg/detail/biped_force_torque_sensors__functions.h"
#include "pronto_msgs/msg/detail/biped_force_torque_sensors__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `l_foot`
// Member `r_foot`
// Member `l_hand`
// Member `r_hand`
#include "geometry_msgs/msg/wrench.h"
// Member `l_foot`
// Member `r_foot`
// Member `l_hand`
// Member `r_hand`
#include "geometry_msgs/msg/detail/wrench__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pronto_msgs__msg__BipedForceTorqueSensors__init(message_memory);
}

void pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_fini_function(void * message_memory)
{
  pronto_msgs__msg__BipedForceTorqueSensors__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__BipedForceTorqueSensors, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "l_foot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__BipedForceTorqueSensors, l_foot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "r_foot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__BipedForceTorqueSensors, r_foot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "l_hand",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__BipedForceTorqueSensors, l_hand),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "r_hand",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pronto_msgs__msg__BipedForceTorqueSensors, r_hand),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_message_members = {
  "pronto_msgs__msg",  // message namespace
  "BipedForceTorqueSensors",  // message name
  5,  // number of fields
  sizeof(pronto_msgs__msg__BipedForceTorqueSensors),
  pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_message_member_array,  // message members
  pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_init_function,  // function to initialize message memory (memory has to be allocated)
  pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_message_type_support_handle = {
  0,
  &pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pronto_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pronto_msgs, msg, BipedForceTorqueSensors)() {
  pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Wrench)();
  pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Wrench)();
  pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Wrench)();
  pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Wrench)();
  if (!pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_message_type_support_handle.typesupport_identifier) {
    pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pronto_msgs__msg__BipedForceTorqueSensors__rosidl_typesupport_introspection_c__BipedForceTorqueSensors_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
