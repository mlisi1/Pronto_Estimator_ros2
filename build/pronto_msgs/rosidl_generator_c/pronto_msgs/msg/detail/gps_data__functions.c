// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pronto_msgs:msg/GPSData.idl
// generated code does not contain a copyright notice
#include "pronto_msgs/msg/detail/gps_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
pronto_msgs__msg__GPSData__init(pronto_msgs__msg__GPSData * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pronto_msgs__msg__GPSData__fini(msg);
    return false;
  }
  // utime
  // gps_lock
  // longitude
  // latitude
  // elev
  // horizontal_accuracy
  // vertical_accuracy
  // num_satellites
  // speed
  // heading
  // xyz_pos
  // gps_time
  return true;
}

void
pronto_msgs__msg__GPSData__fini(pronto_msgs__msg__GPSData * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // utime
  // gps_lock
  // longitude
  // latitude
  // elev
  // horizontal_accuracy
  // vertical_accuracy
  // num_satellites
  // speed
  // heading
  // xyz_pos
  // gps_time
}

bool
pronto_msgs__msg__GPSData__are_equal(const pronto_msgs__msg__GPSData * lhs, const pronto_msgs__msg__GPSData * rhs)
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
  // gps_lock
  if (lhs->gps_lock != rhs->gps_lock) {
    return false;
  }
  // longitude
  if (lhs->longitude != rhs->longitude) {
    return false;
  }
  // latitude
  if (lhs->latitude != rhs->latitude) {
    return false;
  }
  // elev
  if (lhs->elev != rhs->elev) {
    return false;
  }
  // horizontal_accuracy
  if (lhs->horizontal_accuracy != rhs->horizontal_accuracy) {
    return false;
  }
  // vertical_accuracy
  if (lhs->vertical_accuracy != rhs->vertical_accuracy) {
    return false;
  }
  // num_satellites
  if (lhs->num_satellites != rhs->num_satellites) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // heading
  if (lhs->heading != rhs->heading) {
    return false;
  }
  // xyz_pos
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->xyz_pos[i] != rhs->xyz_pos[i]) {
      return false;
    }
  }
  // gps_time
  if (lhs->gps_time != rhs->gps_time) {
    return false;
  }
  return true;
}

bool
pronto_msgs__msg__GPSData__copy(
  const pronto_msgs__msg__GPSData * input,
  pronto_msgs__msg__GPSData * output)
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
  // gps_lock
  output->gps_lock = input->gps_lock;
  // longitude
  output->longitude = input->longitude;
  // latitude
  output->latitude = input->latitude;
  // elev
  output->elev = input->elev;
  // horizontal_accuracy
  output->horizontal_accuracy = input->horizontal_accuracy;
  // vertical_accuracy
  output->vertical_accuracy = input->vertical_accuracy;
  // num_satellites
  output->num_satellites = input->num_satellites;
  // speed
  output->speed = input->speed;
  // heading
  output->heading = input->heading;
  // xyz_pos
  for (size_t i = 0; i < 3; ++i) {
    output->xyz_pos[i] = input->xyz_pos[i];
  }
  // gps_time
  output->gps_time = input->gps_time;
  return true;
}

pronto_msgs__msg__GPSData *
pronto_msgs__msg__GPSData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__GPSData * msg = (pronto_msgs__msg__GPSData *)allocator.allocate(sizeof(pronto_msgs__msg__GPSData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pronto_msgs__msg__GPSData));
  bool success = pronto_msgs__msg__GPSData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pronto_msgs__msg__GPSData__destroy(pronto_msgs__msg__GPSData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pronto_msgs__msg__GPSData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pronto_msgs__msg__GPSData__Sequence__init(pronto_msgs__msg__GPSData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__GPSData * data = NULL;

  if (size) {
    data = (pronto_msgs__msg__GPSData *)allocator.zero_allocate(size, sizeof(pronto_msgs__msg__GPSData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pronto_msgs__msg__GPSData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pronto_msgs__msg__GPSData__fini(&data[i - 1]);
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
pronto_msgs__msg__GPSData__Sequence__fini(pronto_msgs__msg__GPSData__Sequence * array)
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
      pronto_msgs__msg__GPSData__fini(&array->data[i]);
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

pronto_msgs__msg__GPSData__Sequence *
pronto_msgs__msg__GPSData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__GPSData__Sequence * array = (pronto_msgs__msg__GPSData__Sequence *)allocator.allocate(sizeof(pronto_msgs__msg__GPSData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pronto_msgs__msg__GPSData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pronto_msgs__msg__GPSData__Sequence__destroy(pronto_msgs__msg__GPSData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pronto_msgs__msg__GPSData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pronto_msgs__msg__GPSData__Sequence__are_equal(const pronto_msgs__msg__GPSData__Sequence * lhs, const pronto_msgs__msg__GPSData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pronto_msgs__msg__GPSData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pronto_msgs__msg__GPSData__Sequence__copy(
  const pronto_msgs__msg__GPSData__Sequence * input,
  pronto_msgs__msg__GPSData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pronto_msgs__msg__GPSData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pronto_msgs__msg__GPSData * data =
      (pronto_msgs__msg__GPSData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pronto_msgs__msg__GPSData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pronto_msgs__msg__GPSData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pronto_msgs__msg__GPSData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
