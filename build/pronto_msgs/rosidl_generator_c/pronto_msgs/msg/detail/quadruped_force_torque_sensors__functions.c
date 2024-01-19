// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pronto_msgs:msg/QuadrupedForceTorqueSensors.idl
// generated code does not contain a copyright notice
#include "pronto_msgs/msg/detail/quadruped_force_torque_sensors__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `lf`
// Member `rf`
// Member `lh`
// Member `rh`
#include "geometry_msgs/msg/detail/wrench__functions.h"

bool
pronto_msgs__msg__QuadrupedForceTorqueSensors__init(pronto_msgs__msg__QuadrupedForceTorqueSensors * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pronto_msgs__msg__QuadrupedForceTorqueSensors__fini(msg);
    return false;
  }
  // lf
  if (!geometry_msgs__msg__Wrench__init(&msg->lf)) {
    pronto_msgs__msg__QuadrupedForceTorqueSensors__fini(msg);
    return false;
  }
  // rf
  if (!geometry_msgs__msg__Wrench__init(&msg->rf)) {
    pronto_msgs__msg__QuadrupedForceTorqueSensors__fini(msg);
    return false;
  }
  // lh
  if (!geometry_msgs__msg__Wrench__init(&msg->lh)) {
    pronto_msgs__msg__QuadrupedForceTorqueSensors__fini(msg);
    return false;
  }
  // rh
  if (!geometry_msgs__msg__Wrench__init(&msg->rh)) {
    pronto_msgs__msg__QuadrupedForceTorqueSensors__fini(msg);
    return false;
  }
  return true;
}

void
pronto_msgs__msg__QuadrupedForceTorqueSensors__fini(pronto_msgs__msg__QuadrupedForceTorqueSensors * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // lf
  geometry_msgs__msg__Wrench__fini(&msg->lf);
  // rf
  geometry_msgs__msg__Wrench__fini(&msg->rf);
  // lh
  geometry_msgs__msg__Wrench__fini(&msg->lh);
  // rh
  geometry_msgs__msg__Wrench__fini(&msg->rh);
}

bool
pronto_msgs__msg__QuadrupedForceTorqueSensors__are_equal(const pronto_msgs__msg__QuadrupedForceTorqueSensors * lhs, const pronto_msgs__msg__QuadrupedForceTorqueSensors * rhs)
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
  // lf
  if (!geometry_msgs__msg__Wrench__are_equal(
      &(lhs->lf), &(rhs->lf)))
  {
    return false;
  }
  // rf
  if (!geometry_msgs__msg__Wrench__are_equal(
      &(lhs->rf), &(rhs->rf)))
  {
    return false;
  }
  // lh
  if (!geometry_msgs__msg__Wrench__are_equal(
      &(lhs->lh), &(rhs->lh)))
  {
    return false;
  }
  // rh
  if (!geometry_msgs__msg__Wrench__are_equal(
      &(lhs->rh), &(rhs->rh)))
  {
    return false;
  }
  return true;
}

bool
pronto_msgs__msg__QuadrupedForceTorqueSensors__copy(
  const pronto_msgs__msg__QuadrupedForceTorqueSensors * input,
  pronto_msgs__msg__QuadrupedForceTorqueSensors * output)
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
  // lf
  if (!geometry_msgs__msg__Wrench__copy(
      &(input->lf), &(output->lf)))
  {
    return false;
  }
  // rf
  if (!geometry_msgs__msg__Wrench__copy(
      &(input->rf), &(output->rf)))
  {
    return false;
  }
  // lh
  if (!geometry_msgs__msg__Wrench__copy(
      &(input->lh), &(output->lh)))
  {
    return false;
  }
  // rh
  if (!geometry_msgs__msg__Wrench__copy(
      &(input->rh), &(output->rh)))
  {
    return false;
  }
  return true;
}

pronto_msgs__msg__QuadrupedForceTorqueSensors *
pronto_msgs__msg__QuadrupedForceTorqueSensors__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__QuadrupedForceTorqueSensors * msg = (pronto_msgs__msg__QuadrupedForceTorqueSensors *)allocator.allocate(sizeof(pronto_msgs__msg__QuadrupedForceTorqueSensors), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pronto_msgs__msg__QuadrupedForceTorqueSensors));
  bool success = pronto_msgs__msg__QuadrupedForceTorqueSensors__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pronto_msgs__msg__QuadrupedForceTorqueSensors__destroy(pronto_msgs__msg__QuadrupedForceTorqueSensors * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pronto_msgs__msg__QuadrupedForceTorqueSensors__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence__init(pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__QuadrupedForceTorqueSensors * data = NULL;

  if (size) {
    data = (pronto_msgs__msg__QuadrupedForceTorqueSensors *)allocator.zero_allocate(size, sizeof(pronto_msgs__msg__QuadrupedForceTorqueSensors), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pronto_msgs__msg__QuadrupedForceTorqueSensors__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pronto_msgs__msg__QuadrupedForceTorqueSensors__fini(&data[i - 1]);
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
pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence__fini(pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence * array)
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
      pronto_msgs__msg__QuadrupedForceTorqueSensors__fini(&array->data[i]);
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

pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence *
pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence * array = (pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence *)allocator.allocate(sizeof(pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence__destroy(pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence__are_equal(const pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence * lhs, const pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pronto_msgs__msg__QuadrupedForceTorqueSensors__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence__copy(
  const pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence * input,
  pronto_msgs__msg__QuadrupedForceTorqueSensors__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pronto_msgs__msg__QuadrupedForceTorqueSensors);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pronto_msgs__msg__QuadrupedForceTorqueSensors * data =
      (pronto_msgs__msg__QuadrupedForceTorqueSensors *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pronto_msgs__msg__QuadrupedForceTorqueSensors__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pronto_msgs__msg__QuadrupedForceTorqueSensors__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pronto_msgs__msg__QuadrupedForceTorqueSensors__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
