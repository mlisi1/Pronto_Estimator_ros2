// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pronto_msgs:msg/LidarOdometryUpdate.idl
// generated code does not contain a copyright notice
#include "pronto_msgs/msg/detail/lidar_odometry_update__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `curr_timestamp`
// Member `prev_timestamp`
#include "builtin_interfaces/msg/detail/time__functions.h"
// Member `relative_transform`
#include "geometry_msgs/msg/detail/transform__functions.h"

bool
pronto_msgs__msg__LidarOdometryUpdate__init(pronto_msgs__msg__LidarOdometryUpdate * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pronto_msgs__msg__LidarOdometryUpdate__fini(msg);
    return false;
  }
  // curr_timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->curr_timestamp)) {
    pronto_msgs__msg__LidarOdometryUpdate__fini(msg);
    return false;
  }
  // prev_timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->prev_timestamp)) {
    pronto_msgs__msg__LidarOdometryUpdate__fini(msg);
    return false;
  }
  // relative_transform
  if (!geometry_msgs__msg__Transform__init(&msg->relative_transform)) {
    pronto_msgs__msg__LidarOdometryUpdate__fini(msg);
    return false;
  }
  // covariance
  return true;
}

void
pronto_msgs__msg__LidarOdometryUpdate__fini(pronto_msgs__msg__LidarOdometryUpdate * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // curr_timestamp
  builtin_interfaces__msg__Time__fini(&msg->curr_timestamp);
  // prev_timestamp
  builtin_interfaces__msg__Time__fini(&msg->prev_timestamp);
  // relative_transform
  geometry_msgs__msg__Transform__fini(&msg->relative_transform);
  // covariance
}

bool
pronto_msgs__msg__LidarOdometryUpdate__are_equal(const pronto_msgs__msg__LidarOdometryUpdate * lhs, const pronto_msgs__msg__LidarOdometryUpdate * rhs)
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
  // curr_timestamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->curr_timestamp), &(rhs->curr_timestamp)))
  {
    return false;
  }
  // prev_timestamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->prev_timestamp), &(rhs->prev_timestamp)))
  {
    return false;
  }
  // relative_transform
  if (!geometry_msgs__msg__Transform__are_equal(
      &(lhs->relative_transform), &(rhs->relative_transform)))
  {
    return false;
  }
  // covariance
  for (size_t i = 0; i < 36; ++i) {
    if (lhs->covariance[i] != rhs->covariance[i]) {
      return false;
    }
  }
  return true;
}

bool
pronto_msgs__msg__LidarOdometryUpdate__copy(
  const pronto_msgs__msg__LidarOdometryUpdate * input,
  pronto_msgs__msg__LidarOdometryUpdate * output)
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
  // curr_timestamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->curr_timestamp), &(output->curr_timestamp)))
  {
    return false;
  }
  // prev_timestamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->prev_timestamp), &(output->prev_timestamp)))
  {
    return false;
  }
  // relative_transform
  if (!geometry_msgs__msg__Transform__copy(
      &(input->relative_transform), &(output->relative_transform)))
  {
    return false;
  }
  // covariance
  for (size_t i = 0; i < 36; ++i) {
    output->covariance[i] = input->covariance[i];
  }
  return true;
}

pronto_msgs__msg__LidarOdometryUpdate *
pronto_msgs__msg__LidarOdometryUpdate__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__LidarOdometryUpdate * msg = (pronto_msgs__msg__LidarOdometryUpdate *)allocator.allocate(sizeof(pronto_msgs__msg__LidarOdometryUpdate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pronto_msgs__msg__LidarOdometryUpdate));
  bool success = pronto_msgs__msg__LidarOdometryUpdate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pronto_msgs__msg__LidarOdometryUpdate__destroy(pronto_msgs__msg__LidarOdometryUpdate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pronto_msgs__msg__LidarOdometryUpdate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pronto_msgs__msg__LidarOdometryUpdate__Sequence__init(pronto_msgs__msg__LidarOdometryUpdate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__LidarOdometryUpdate * data = NULL;

  if (size) {
    data = (pronto_msgs__msg__LidarOdometryUpdate *)allocator.zero_allocate(size, sizeof(pronto_msgs__msg__LidarOdometryUpdate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pronto_msgs__msg__LidarOdometryUpdate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pronto_msgs__msg__LidarOdometryUpdate__fini(&data[i - 1]);
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
pronto_msgs__msg__LidarOdometryUpdate__Sequence__fini(pronto_msgs__msg__LidarOdometryUpdate__Sequence * array)
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
      pronto_msgs__msg__LidarOdometryUpdate__fini(&array->data[i]);
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

pronto_msgs__msg__LidarOdometryUpdate__Sequence *
pronto_msgs__msg__LidarOdometryUpdate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__LidarOdometryUpdate__Sequence * array = (pronto_msgs__msg__LidarOdometryUpdate__Sequence *)allocator.allocate(sizeof(pronto_msgs__msg__LidarOdometryUpdate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pronto_msgs__msg__LidarOdometryUpdate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pronto_msgs__msg__LidarOdometryUpdate__Sequence__destroy(pronto_msgs__msg__LidarOdometryUpdate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pronto_msgs__msg__LidarOdometryUpdate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pronto_msgs__msg__LidarOdometryUpdate__Sequence__are_equal(const pronto_msgs__msg__LidarOdometryUpdate__Sequence * lhs, const pronto_msgs__msg__LidarOdometryUpdate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pronto_msgs__msg__LidarOdometryUpdate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pronto_msgs__msg__LidarOdometryUpdate__Sequence__copy(
  const pronto_msgs__msg__LidarOdometryUpdate__Sequence * input,
  pronto_msgs__msg__LidarOdometryUpdate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pronto_msgs__msg__LidarOdometryUpdate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pronto_msgs__msg__LidarOdometryUpdate * data =
      (pronto_msgs__msg__LidarOdometryUpdate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pronto_msgs__msg__LidarOdometryUpdate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pronto_msgs__msg__LidarOdometryUpdate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pronto_msgs__msg__LidarOdometryUpdate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
