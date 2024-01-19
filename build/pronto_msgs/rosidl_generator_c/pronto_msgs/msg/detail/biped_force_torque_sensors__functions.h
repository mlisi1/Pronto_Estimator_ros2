// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from pronto_msgs:msg/BipedForceTorqueSensors.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__BIPED_FORCE_TORQUE_SENSORS__FUNCTIONS_H_
#define PRONTO_MSGS__MSG__DETAIL__BIPED_FORCE_TORQUE_SENSORS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "pronto_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "pronto_msgs/msg/detail/biped_force_torque_sensors__struct.h"

/// Initialize msg/BipedForceTorqueSensors message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pronto_msgs__msg__BipedForceTorqueSensors
 * )) before or use
 * pronto_msgs__msg__BipedForceTorqueSensors__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
bool
pronto_msgs__msg__BipedForceTorqueSensors__init(pronto_msgs__msg__BipedForceTorqueSensors * msg);

/// Finalize msg/BipedForceTorqueSensors message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
void
pronto_msgs__msg__BipedForceTorqueSensors__fini(pronto_msgs__msg__BipedForceTorqueSensors * msg);

/// Create msg/BipedForceTorqueSensors message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pronto_msgs__msg__BipedForceTorqueSensors__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
pronto_msgs__msg__BipedForceTorqueSensors *
pronto_msgs__msg__BipedForceTorqueSensors__create();

/// Destroy msg/BipedForceTorqueSensors message.
/**
 * It calls
 * pronto_msgs__msg__BipedForceTorqueSensors__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
void
pronto_msgs__msg__BipedForceTorqueSensors__destroy(pronto_msgs__msg__BipedForceTorqueSensors * msg);

/// Check for msg/BipedForceTorqueSensors message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
bool
pronto_msgs__msg__BipedForceTorqueSensors__are_equal(const pronto_msgs__msg__BipedForceTorqueSensors * lhs, const pronto_msgs__msg__BipedForceTorqueSensors * rhs);

/// Copy a msg/BipedForceTorqueSensors message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
bool
pronto_msgs__msg__BipedForceTorqueSensors__copy(
  const pronto_msgs__msg__BipedForceTorqueSensors * input,
  pronto_msgs__msg__BipedForceTorqueSensors * output);

/// Initialize array of msg/BipedForceTorqueSensors messages.
/**
 * It allocates the memory for the number of elements and calls
 * pronto_msgs__msg__BipedForceTorqueSensors__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
bool
pronto_msgs__msg__BipedForceTorqueSensors__Sequence__init(pronto_msgs__msg__BipedForceTorqueSensors__Sequence * array, size_t size);

/// Finalize array of msg/BipedForceTorqueSensors messages.
/**
 * It calls
 * pronto_msgs__msg__BipedForceTorqueSensors__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
void
pronto_msgs__msg__BipedForceTorqueSensors__Sequence__fini(pronto_msgs__msg__BipedForceTorqueSensors__Sequence * array);

/// Create array of msg/BipedForceTorqueSensors messages.
/**
 * It allocates the memory for the array and calls
 * pronto_msgs__msg__BipedForceTorqueSensors__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
pronto_msgs__msg__BipedForceTorqueSensors__Sequence *
pronto_msgs__msg__BipedForceTorqueSensors__Sequence__create(size_t size);

/// Destroy array of msg/BipedForceTorqueSensors messages.
/**
 * It calls
 * pronto_msgs__msg__BipedForceTorqueSensors__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
void
pronto_msgs__msg__BipedForceTorqueSensors__Sequence__destroy(pronto_msgs__msg__BipedForceTorqueSensors__Sequence * array);

/// Check for msg/BipedForceTorqueSensors message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
bool
pronto_msgs__msg__BipedForceTorqueSensors__Sequence__are_equal(const pronto_msgs__msg__BipedForceTorqueSensors__Sequence * lhs, const pronto_msgs__msg__BipedForceTorqueSensors__Sequence * rhs);

/// Copy an array of msg/BipedForceTorqueSensors messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
bool
pronto_msgs__msg__BipedForceTorqueSensors__Sequence__copy(
  const pronto_msgs__msg__BipedForceTorqueSensors__Sequence * input,
  pronto_msgs__msg__BipedForceTorqueSensors__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PRONTO_MSGS__MSG__DETAIL__BIPED_FORCE_TORQUE_SENSORS__FUNCTIONS_H_
