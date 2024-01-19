// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pronto_msgs:msg/BipedForceTorqueSensors.idl
// generated code does not contain a copyright notice
#include "pronto_msgs/msg/detail/biped_force_torque_sensors__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `l_foot`
// Member `r_foot`
// Member `l_hand`
// Member `r_hand`
#include "geometry_msgs/msg/detail/wrench__functions.h"

bool
pronto_msgs__msg__BipedForceTorqueSensors__init(pronto_msgs__msg__BipedForceTorqueSensors * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pronto_msgs__msg__BipedForceTorqueSensors__fini(msg);
    return false;
  }
  // l_foot
  if (!geometry_msgs__msg__Wrench__init(&msg->l_foot)) {
    pronto_msgs__msg__BipedForceTorqueSensors__fini(msg);
    return false;
  }
  // r_foot
  if (!geometry_msgs__msg__Wrench__init(&msg->r_foot)) {
    pronto_msgs__msg__BipedForceTorqueSensors__fini(msg);
    return false;
  }
  // l_hand
  if (!geometry_msgs__msg__Wrench__init(&msg->l_hand)) {
    pronto_msgs__msg__BipedForceTorqueSensors__fini(msg);
    return false;
  }
  // r_hand
  if (!geometry_msgs__msg__Wrench__init(&msg->r_hand)) {
    pronto_msgs__msg__BipedForceTorqueSensors__fini(msg);
    return false;
  }
  return true;
}

void
pronto_msgs__msg__BipedForceTorqueSensors__fini(pronto_msgs__msg__BipedForceTorqueSensors * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // l_foot
  geometry_msgs__msg__Wrench__fini(&msg->l_foot);
  // r_foot
  geometry_msgs__msg__Wrench__fini(&msg->r_foot);
  // l_hand
  geometry_msgs__msg__Wrench__fini(&msg->l_hand);
  // r_hand
  geometry_msgs__msg__Wrench__fini(&msg->r_hand);
}

bool
pronto_msgs__msg__BipedForceTorqueSensors__are_equal(const pronto_msgs__msg__BipedForceTorqueSensors * lhs, const pronto_msgs__msg__BipedForceTorqueSensors * rhs)
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
  // l_foot
  if (!geometry_msgs__msg__Wrench__are_equal(
      &(lhs->l_foot), &(rhs->l_foot)))
  {
    return false;
  }
  // r_foot
  if (!geometry_msgs__msg__Wrench__are_equal(
      &(lhs->r_foot), &(rhs->r_foot)))
  {
    return false;
  }
  // l_hand
  if (!geometry_msgs__msg__Wrench__are_equal(
      &(lhs->l_hand), &(rhs->l_hand)))
  {
    return false;
  }
  // r_hand
  if (!geometry_msgs__msg__Wrench__are_equal(
      &(lhs->r_hand), &(rhs->r_hand)))
  {
    return false;
  }
  return true;
}

bool
pronto_msgs__msg__BipedForceTorqueSensors__copy(
  const pronto_msgs__msg__BipedForceTorqueSensors * input,
  pronto_msgs__msg__BipedForceTorqueSensors * output)
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
  // l_foot
  if (!geometry_msgs__msg__Wrench__copy(
      &(input->l_foot), &(output->l_foot)))
  {
    return false;
  }
  // r_foot
  if (!geometry_msgs__msg__Wrench__copy(
      &(input->r_foot), &(output->r_foot)))
  {
    return false;
  }
  // l_hand
  if (!geometry_msgs__msg__Wrench__copy(
      &(input->l_hand), &(output->l_hand)))
  {
    return false;
  }
  // r_hand
  if (!geometry_msgs__msg__Wrench__copy(
      &(input->r_hand), &(output->r_hand)))
  {
    return false;
  }
  return true;
}

pronto_msgs__msg__BipedForceTorqueSensors *
pronto_msgs__msg__BipedForceTorqueSensors__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__BipedForceTorqueSensors * msg = (pronto_msgs__msg__BipedForceTorqueSensors *)allocator.allocate(sizeof(pronto_msgs__msg__BipedForceTorqueSensors), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pronto_msgs__msg__BipedForceTorqueSensors));
  bool success = pronto_msgs__msg__BipedForceTorqueSensors__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pronto_msgs__msg__BipedForceTorqueSensors__destroy(pronto_msgs__msg__BipedForceTorqueSensors * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pronto_msgs__msg__BipedForceTorqueSensors__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pronto_msgs__msg__BipedForceTorqueSensors__Sequence__init(pronto_msgs__msg__BipedForceTorqueSensors__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__BipedForceTorqueSensors * data = NULL;

  if (size) {
    data = (pronto_msgs__msg__BipedForceTorqueSensors *)allocator.zero_allocate(size, sizeof(pronto_msgs__msg__BipedForceTorqueSensors), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pronto_msgs__msg__BipedForceTorqueSensors__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pronto_msgs__msg__BipedForceTorqueSensors__fini(&data[i - 1]);
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
pronto_msgs__msg__BipedForceTorqueSensors__Sequence__fini(pronto_msgs__msg__BipedForceTorqueSensors__Sequence * array)
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
      pronto_msgs__msg__BipedForceTorqueSensors__fini(&array->data[i]);
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

pronto_msgs__msg__BipedForceTorqueSensors__Sequence *
pronto_msgs__msg__BipedForceTorqueSensors__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__BipedForceTorqueSensors__Sequence * array = (pronto_msgs__msg__BipedForceTorqueSensors__Sequence *)allocator.allocate(sizeof(pronto_msgs__msg__BipedForceTorqueSensors__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pronto_msgs__msg__BipedForceTorqueSensors__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pronto_msgs__msg__BipedForceTorqueSensors__Sequence__destroy(pronto_msgs__msg__BipedForceTorqueSensors__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pronto_msgs__msg__BipedForceTorqueSensors__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pronto_msgs__msg__BipedForceTorqueSensors__Sequence__are_equal(const pronto_msgs__msg__BipedForceTorqueSensors__Sequence * lhs, const pronto_msgs__msg__BipedForceTorqueSensors__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pronto_msgs__msg__BipedForceTorqueSensors__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pronto_msgs__msg__BipedForceTorqueSensors__Sequence__copy(
  const pronto_msgs__msg__BipedForceTorqueSensors__Sequence * input,
  pronto_msgs__msg__BipedForceTorqueSensors__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pronto_msgs__msg__BipedForceTorqueSensors);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pronto_msgs__msg__BipedForceTorqueSensors * data =
      (pronto_msgs__msg__BipedForceTorqueSensors *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pronto_msgs__msg__BipedForceTorqueSensors__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pronto_msgs__msg__BipedForceTorqueSensors__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pronto_msgs__msg__BipedForceTorqueSensors__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
