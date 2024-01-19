// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pronto_msgs:msg/IndexedMeasurement.idl
// generated code does not contain a copyright notice
#include "pronto_msgs/msg/detail/indexed_measurement__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `z_effective`
// Member `z_indices`
// Member `r_effective`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
pronto_msgs__msg__IndexedMeasurement__init(pronto_msgs__msg__IndexedMeasurement * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pronto_msgs__msg__IndexedMeasurement__fini(msg);
    return false;
  }
  // utime
  // state_utime
  // z_effective
  if (!rosidl_runtime_c__double__Sequence__init(&msg->z_effective, 0)) {
    pronto_msgs__msg__IndexedMeasurement__fini(msg);
    return false;
  }
  // z_indices
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->z_indices, 0)) {
    pronto_msgs__msg__IndexedMeasurement__fini(msg);
    return false;
  }
  // r_effective
  if (!rosidl_runtime_c__double__Sequence__init(&msg->r_effective, 0)) {
    pronto_msgs__msg__IndexedMeasurement__fini(msg);
    return false;
  }
  return true;
}

void
pronto_msgs__msg__IndexedMeasurement__fini(pronto_msgs__msg__IndexedMeasurement * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // utime
  // state_utime
  // z_effective
  rosidl_runtime_c__double__Sequence__fini(&msg->z_effective);
  // z_indices
  rosidl_runtime_c__int32__Sequence__fini(&msg->z_indices);
  // r_effective
  rosidl_runtime_c__double__Sequence__fini(&msg->r_effective);
}

bool
pronto_msgs__msg__IndexedMeasurement__are_equal(const pronto_msgs__msg__IndexedMeasurement * lhs, const pronto_msgs__msg__IndexedMeasurement * rhs)
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
  // utime
  if (lhs->utime != rhs->utime) {
    return false;
  }
  // state_utime
  if (lhs->state_utime != rhs->state_utime) {
    return false;
  }
  // z_effective
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->z_effective), &(rhs->z_effective)))
  {
    return false;
  }
  // z_indices
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->z_indices), &(rhs->z_indices)))
  {
    return false;
  }
  // r_effective
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->r_effective), &(rhs->r_effective)))
  {
    return false;
  }
  return true;
}

bool
pronto_msgs__msg__IndexedMeasurement__copy(
  const pronto_msgs__msg__IndexedMeasurement * input,
  pronto_msgs__msg__IndexedMeasurement * output)
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
  // utime
  output->utime = input->utime;
  // state_utime
  output->state_utime = input->state_utime;
  // z_effective
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->z_effective), &(output->z_effective)))
  {
    return false;
  }
  // z_indices
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->z_indices), &(output->z_indices)))
  {
    return false;
  }
  // r_effective
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->r_effective), &(output->r_effective)))
  {
    return false;
  }
  return true;
}

pronto_msgs__msg__IndexedMeasurement *
pronto_msgs__msg__IndexedMeasurement__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__IndexedMeasurement * msg = (pronto_msgs__msg__IndexedMeasurement *)allocator.allocate(sizeof(pronto_msgs__msg__IndexedMeasurement), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pronto_msgs__msg__IndexedMeasurement));
  bool success = pronto_msgs__msg__IndexedMeasurement__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pronto_msgs__msg__IndexedMeasurement__destroy(pronto_msgs__msg__IndexedMeasurement * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pronto_msgs__msg__IndexedMeasurement__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pronto_msgs__msg__IndexedMeasurement__Sequence__init(pronto_msgs__msg__IndexedMeasurement__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__IndexedMeasurement * data = NULL;

  if (size) {
    data = (pronto_msgs__msg__IndexedMeasurement *)allocator.zero_allocate(size, sizeof(pronto_msgs__msg__IndexedMeasurement), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pronto_msgs__msg__IndexedMeasurement__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pronto_msgs__msg__IndexedMeasurement__fini(&data[i - 1]);
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
pronto_msgs__msg__IndexedMeasurement__Sequence__fini(pronto_msgs__msg__IndexedMeasurement__Sequence * array)
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
      pronto_msgs__msg__IndexedMeasurement__fini(&array->data[i]);
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

pronto_msgs__msg__IndexedMeasurement__Sequence *
pronto_msgs__msg__IndexedMeasurement__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__IndexedMeasurement__Sequence * array = (pronto_msgs__msg__IndexedMeasurement__Sequence *)allocator.allocate(sizeof(pronto_msgs__msg__IndexedMeasurement__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pronto_msgs__msg__IndexedMeasurement__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pronto_msgs__msg__IndexedMeasurement__Sequence__destroy(pronto_msgs__msg__IndexedMeasurement__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pronto_msgs__msg__IndexedMeasurement__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pronto_msgs__msg__IndexedMeasurement__Sequence__are_equal(const pronto_msgs__msg__IndexedMeasurement__Sequence * lhs, const pronto_msgs__msg__IndexedMeasurement__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pronto_msgs__msg__IndexedMeasurement__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pronto_msgs__msg__IndexedMeasurement__Sequence__copy(
  const pronto_msgs__msg__IndexedMeasurement__Sequence * input,
  pronto_msgs__msg__IndexedMeasurement__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pronto_msgs__msg__IndexedMeasurement);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pronto_msgs__msg__IndexedMeasurement * data =
      (pronto_msgs__msg__IndexedMeasurement *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pronto_msgs__msg__IndexedMeasurement__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pronto_msgs__msg__IndexedMeasurement__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pronto_msgs__msg__IndexedMeasurement__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
