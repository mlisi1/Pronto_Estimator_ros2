// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pronto_msgs:msg/VelocityWithSigmaBounds.idl
// generated code does not contain a copyright notice
#include "pronto_msgs/msg/detail/velocity_with_sigma_bounds__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `velocity_plus_one_sigma`
// Member `velocity_minus_one_sigma`
// Member `plus_one_sigma`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
pronto_msgs__msg__VelocityWithSigmaBounds__init(pronto_msgs__msg__VelocityWithSigmaBounds * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pronto_msgs__msg__VelocityWithSigmaBounds__fini(msg);
    return false;
  }
  // velocity_plus_one_sigma
  if (!geometry_msgs__msg__Vector3__init(&msg->velocity_plus_one_sigma)) {
    pronto_msgs__msg__VelocityWithSigmaBounds__fini(msg);
    return false;
  }
  // velocity_minus_one_sigma
  if (!geometry_msgs__msg__Vector3__init(&msg->velocity_minus_one_sigma)) {
    pronto_msgs__msg__VelocityWithSigmaBounds__fini(msg);
    return false;
  }
  // plus_one_sigma
  if (!geometry_msgs__msg__Vector3__init(&msg->plus_one_sigma)) {
    pronto_msgs__msg__VelocityWithSigmaBounds__fini(msg);
    return false;
  }
  return true;
}

void
pronto_msgs__msg__VelocityWithSigmaBounds__fini(pronto_msgs__msg__VelocityWithSigmaBounds * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // velocity_plus_one_sigma
  geometry_msgs__msg__Vector3__fini(&msg->velocity_plus_one_sigma);
  // velocity_minus_one_sigma
  geometry_msgs__msg__Vector3__fini(&msg->velocity_minus_one_sigma);
  // plus_one_sigma
  geometry_msgs__msg__Vector3__fini(&msg->plus_one_sigma);
}

bool
pronto_msgs__msg__VelocityWithSigmaBounds__are_equal(const pronto_msgs__msg__VelocityWithSigmaBounds * lhs, const pronto_msgs__msg__VelocityWithSigmaBounds * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // velocity_plus_one_sigma
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->velocity_plus_one_sigma), &(rhs->velocity_plus_one_sigma)))
  {
    return false;
  }
  // velocity_minus_one_sigma
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->velocity_minus_one_sigma), &(rhs->velocity_minus_one_sigma)))
  {
    return false;
  }
  // plus_one_sigma
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->plus_one_sigma), &(rhs->plus_one_sigma)))
  {
    return false;
  }
  return true;
}

bool
pronto_msgs__msg__VelocityWithSigmaBounds__copy(
  const pronto_msgs__msg__VelocityWithSigmaBounds * input,
  pronto_msgs__msg__VelocityWithSigmaBounds * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // velocity_plus_one_sigma
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->velocity_plus_one_sigma), &(output->velocity_plus_one_sigma)))
  {
    return false;
  }
  // velocity_minus_one_sigma
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->velocity_minus_one_sigma), &(output->velocity_minus_one_sigma)))
  {
    return false;
  }
  // plus_one_sigma
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->plus_one_sigma), &(output->plus_one_sigma)))
  {
    return false;
  }
  return true;
}

pronto_msgs__msg__VelocityWithSigmaBounds *
pronto_msgs__msg__VelocityWithSigmaBounds__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__VelocityWithSigmaBounds * msg = (pronto_msgs__msg__VelocityWithSigmaBounds *)allocator.allocate(sizeof(pronto_msgs__msg__VelocityWithSigmaBounds), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pronto_msgs__msg__VelocityWithSigmaBounds));
  bool success = pronto_msgs__msg__VelocityWithSigmaBounds__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pronto_msgs__msg__VelocityWithSigmaBounds__destroy(pronto_msgs__msg__VelocityWithSigmaBounds * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pronto_msgs__msg__VelocityWithSigmaBounds__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__init(pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__VelocityWithSigmaBounds * data = NULL;

  if (size) {
    data = (pronto_msgs__msg__VelocityWithSigmaBounds *)allocator.zero_allocate(size, sizeof(pronto_msgs__msg__VelocityWithSigmaBounds), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pronto_msgs__msg__VelocityWithSigmaBounds__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pronto_msgs__msg__VelocityWithSigmaBounds__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__fini(pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pronto_msgs__msg__VelocityWithSigmaBounds__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pronto_msgs__msg__VelocityWithSigmaBounds__Sequence *
pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * array = (pronto_msgs__msg__VelocityWithSigmaBounds__Sequence *)allocator.allocate(sizeof(pronto_msgs__msg__VelocityWithSigmaBounds__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__destroy(pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__are_equal(const pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * lhs, const pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pronto_msgs__msg__VelocityWithSigmaBounds__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pronto_msgs__msg__VelocityWithSigmaBounds__Sequence__copy(
  const pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * input,
  pronto_msgs__msg__VelocityWithSigmaBounds__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pronto_msgs__msg__VelocityWithSigmaBounds);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pronto_msgs__msg__VelocityWithSigmaBounds * data =
      (pronto_msgs__msg__VelocityWithSigmaBounds *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pronto_msgs__msg__VelocityWithSigmaBounds__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pronto_msgs__msg__VelocityWithSigmaBounds__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pronto_msgs__msg__VelocityWithSigmaBounds__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
