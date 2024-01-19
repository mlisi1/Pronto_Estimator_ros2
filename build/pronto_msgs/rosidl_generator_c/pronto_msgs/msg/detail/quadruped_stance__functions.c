// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pronto_msgs:msg/QuadrupedStance.idl
// generated code does not contain a copyright notice
#include "pronto_msgs/msg/detail/quadruped_stance__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
pronto_msgs__msg__QuadrupedStance__init(pronto_msgs__msg__QuadrupedStance * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pronto_msgs__msg__QuadrupedStance__fini(msg);
    return false;
  }
  // lf
  // rf
  // lh
  // rh
  return true;
}

void
pronto_msgs__msg__QuadrupedStance__fini(pronto_msgs__msg__QuadrupedStance * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // lf
  // rf
  // lh
  // rh
}

bool
pronto_msgs__msg__QuadrupedStance__are_equal(const pronto_msgs__msg__QuadrupedStance * lhs, const pronto_msgs__msg__QuadrupedStance * rhs)
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
  if (lhs->lf != rhs->lf) {
    return false;
  }
  // rf
  if (lhs->rf != rhs->rf) {
    return false;
  }
  // lh
  if (lhs->lh != rhs->lh) {
    return false;
  }
  // rh
  if (lhs->rh != rhs->rh) {
    return false;
  }
  return true;
}

bool
pronto_msgs__msg__QuadrupedStance__copy(
  const pronto_msgs__msg__QuadrupedStance * input,
  pronto_msgs__msg__QuadrupedStance * output)
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
  output->lf = input->lf;
  // rf
  output->rf = input->rf;
  // lh
  output->lh = input->lh;
  // rh
  output->rh = input->rh;
  return true;
}

pronto_msgs__msg__QuadrupedStance *
pronto_msgs__msg__QuadrupedStance__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__QuadrupedStance * msg = (pronto_msgs__msg__QuadrupedStance *)allocator.allocate(sizeof(pronto_msgs__msg__QuadrupedStance), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pronto_msgs__msg__QuadrupedStance));
  bool success = pronto_msgs__msg__QuadrupedStance__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pronto_msgs__msg__QuadrupedStance__destroy(pronto_msgs__msg__QuadrupedStance * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pronto_msgs__msg__QuadrupedStance__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pronto_msgs__msg__QuadrupedStance__Sequence__init(pronto_msgs__msg__QuadrupedStance__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__QuadrupedStance * data = NULL;

  if (size) {
    data = (pronto_msgs__msg__QuadrupedStance *)allocator.zero_allocate(size, sizeof(pronto_msgs__msg__QuadrupedStance), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pronto_msgs__msg__QuadrupedStance__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pronto_msgs__msg__QuadrupedStance__fini(&data[i - 1]);
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
pronto_msgs__msg__QuadrupedStance__Sequence__fini(pronto_msgs__msg__QuadrupedStance__Sequence * array)
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
      pronto_msgs__msg__QuadrupedStance__fini(&array->data[i]);
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

pronto_msgs__msg__QuadrupedStance__Sequence *
pronto_msgs__msg__QuadrupedStance__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__QuadrupedStance__Sequence * array = (pronto_msgs__msg__QuadrupedStance__Sequence *)allocator.allocate(sizeof(pronto_msgs__msg__QuadrupedStance__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pronto_msgs__msg__QuadrupedStance__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pronto_msgs__msg__QuadrupedStance__Sequence__destroy(pronto_msgs__msg__QuadrupedStance__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pronto_msgs__msg__QuadrupedStance__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pronto_msgs__msg__QuadrupedStance__Sequence__are_equal(const pronto_msgs__msg__QuadrupedStance__Sequence * lhs, const pronto_msgs__msg__QuadrupedStance__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pronto_msgs__msg__QuadrupedStance__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pronto_msgs__msg__QuadrupedStance__Sequence__copy(
  const pronto_msgs__msg__QuadrupedStance__Sequence * input,
  pronto_msgs__msg__QuadrupedStance__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pronto_msgs__msg__QuadrupedStance);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pronto_msgs__msg__QuadrupedStance * data =
      (pronto_msgs__msg__QuadrupedStance *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pronto_msgs__msg__QuadrupedStance__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pronto_msgs__msg__QuadrupedStance__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pronto_msgs__msg__QuadrupedStance__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
