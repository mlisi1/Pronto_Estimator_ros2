// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from pronto_msgs:msg/GPSData.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__GPS_DATA__FUNCTIONS_H_
#define PRONTO_MSGS__MSG__DETAIL__GPS_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "pronto_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "pronto_msgs/msg/detail/gps_data__struct.h"

/// Initialize msg/GPSData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pronto_msgs__msg__GPSData
 * )) before or use
 * pronto_msgs__msg__GPSData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
bool
pronto_msgs__msg__GPSData__init(pronto_msgs__msg__GPSData * msg);

/// Finalize msg/GPSData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
void
pronto_msgs__msg__GPSData__fini(pronto_msgs__msg__GPSData * msg);

/// Create msg/GPSData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pronto_msgs__msg__GPSData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
pronto_msgs__msg__GPSData *
pronto_msgs__msg__GPSData__create();

/// Destroy msg/GPSData message.
/**
 * It calls
 * pronto_msgs__msg__GPSData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
void
pronto_msgs__msg__GPSData__destroy(pronto_msgs__msg__GPSData * msg);

/// Check for msg/GPSData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
bool
pronto_msgs__msg__GPSData__are_equal(const pronto_msgs__msg__GPSData * lhs, const pronto_msgs__msg__GPSData * rhs);

/// Copy a msg/GPSData message.
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
pronto_msgs__msg__GPSData__copy(
  const pronto_msgs__msg__GPSData * input,
  pronto_msgs__msg__GPSData * output);

/// Initialize array of msg/GPSData messages.
/**
 * It allocates the memory for the number of elements and calls
 * pronto_msgs__msg__GPSData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
bool
pronto_msgs__msg__GPSData__Sequence__init(pronto_msgs__msg__GPSData__Sequence * array, size_t size);

/// Finalize array of msg/GPSData messages.
/**
 * It calls
 * pronto_msgs__msg__GPSData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
void
pronto_msgs__msg__GPSData__Sequence__fini(pronto_msgs__msg__GPSData__Sequence * array);

/// Create array of msg/GPSData messages.
/**
 * It allocates the memory for the array and calls
 * pronto_msgs__msg__GPSData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
pronto_msgs__msg__GPSData__Sequence *
pronto_msgs__msg__GPSData__Sequence__create(size_t size);

/// Destroy array of msg/GPSData messages.
/**
 * It calls
 * pronto_msgs__msg__GPSData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
void
pronto_msgs__msg__GPSData__Sequence__destroy(pronto_msgs__msg__GPSData__Sequence * array);

/// Check for msg/GPSData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
bool
pronto_msgs__msg__GPSData__Sequence__are_equal(const pronto_msgs__msg__GPSData__Sequence * lhs, const pronto_msgs__msg__GPSData__Sequence * rhs);

/// Copy an array of msg/GPSData messages.
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
pronto_msgs__msg__GPSData__Sequence__copy(
  const pronto_msgs__msg__GPSData__Sequence * input,
  pronto_msgs__msg__GPSData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PRONTO_MSGS__MSG__DETAIL__GPS_DATA__FUNCTIONS_H_
