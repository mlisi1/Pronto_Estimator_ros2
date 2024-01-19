// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from pronto_msgs:msg/VelocityWithSigmaBounds.idl
// generated code does not contain a copyright notice

#ifndef PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__FUNCTIONS_H_
#define PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "pronto_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "pronto_msgs/msg/detail/velocity_with_sigma_bounds__struct.h"

/// Initialize msg/VelocityWithSigmaBounds message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pronto_msgs__msg__VelocityWithSigmaBounds
 * )) before or use
 * pronto_msgs__msg__VelocityWithSigmaBounds__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
bool
pronto_msgs__msg__VelocityWithSigmaBounds__init(pronto_msgs__msg__VelocityWithSigmaBounds * msg);

/// Finalize msg/VelocityWithSigmaBounds message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
void
pronto_msgs__msg__VelocityWithSigmaBounds__fini(pronto_msgs__msg__VelocityWithSigmaBounds * msg);

/// Create msg/VelocityWithSigmaBounds message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pronto_msgs__msg__VelocityWithSigmaBounds__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
pronto_msgs__msg__VelocityWithSigmaBounds *
pronto_msgs__msg__VelocityWithSigmaBounds__create();

/// Destroy msg/VelocityWithSigmaBounds message.
/**
 * It calls
 * pronto_msgs__msg__VelocityWithSigmaBounds__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
void
pronto_msgs__msg__VelocityWithSigmaBounds__destroy(pronto_msgs__msg__VelocityWithSigmaBounds * msg);

/// Check for msg/VelocityWithSigmaBounds message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
bool
pronto_msgs__msg__VelocityWithSigmaBounds__are_equal(const pronto_msgs__msg__VelocityWithSigmaBounds * lhs, const pronto_msgs__msg__VelocityWithSigmaBounds * rhs);

/// Copy a msg/VelocityWithSigmaBounds message.
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
pronto_msgs__msg__VelocityWithSigmaBounds__copy(
  const pronto_msgs__msg__VelocityWithSigmaBounds * input,
  pronto_msgs__msg__VelocityWithSigmaBounds * output);

/// Initialize array of msg/VelocityWithSigmaBounds messages.
/**
 * It allocates the memory for the number of elements and calls
 * pronto_msgs__msg__VelocityWithSigmaBounds__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
bool
pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__init(pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * array, size_t size);

/// Finalize array of msg/VelocityWithSigmaBounds messages.
/**
 * It calls
 * pronto_msgs__msg__VelocityWithSigmaBounds__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
void
pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__fini(pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * array);

/// Create array of msg/VelocityWithSigmaBounds messages.
/**
 * It allocates the memory for the array and calls
 * pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
pronto_msgs__msg__VelocityWithSigmaBounds__Sequence *
pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__create(size_t size);

/// Destroy array of msg/VelocityWithSigmaBounds messages.
/**
 * It calls
 * pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
void
pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__destroy(pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * array);

/// Check for msg/VelocityWithSigmaBounds message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pronto_msgs
bool
pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__are_equal(const pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * lhs, const pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * rhs);

/// Copy an array of msg/VelocityWithSigmaBounds messages.
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
pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__copy(
  const pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * input,
  pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PRONTO_MSGS__MSG__DETAIL__VELOCITY_WITH_SIGMA_BOUNDS__FUNCTIONS_H_
