// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pronto_msgs:msg/ControllerFootContact.idl
// generated code does not contain a copyright notice
#include "pronto_msgs/msg/detail/controller_foot_contact__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `right_foot_contacts`
// Member `left_foot_contacts`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
pronto_msgs__msg__ControllerFootContact__init(pronto_msgs__msg__ControllerFootContact * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pronto_msgs__msg__ControllerFootContact__fini(msg);
    return false;
  }
  // num_right_foot_contacts
  // right_foot_contacts
  if (!rosidl_runtime_c__double__Sequence__init(&msg->right_foot_contacts, 0)) {
    pronto_msgs__msg__ControllerFootContact__fini(msg);
    return false;
  }
  // num_left_foot_contacts
  // left_foot_contacts
  if (!rosidl_runtime_c__double__Sequence__init(&msg->left_foot_contacts, 0)) {
    pronto_msgs__msg__ControllerFootContact__fini(msg);
    return false;
  }
  return true;
}

void
pronto_msgs__msg__ControllerFootContact__fini(pronto_msgs__msg__ControllerFootContact * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // num_right_foot_contacts
  // right_foot_contacts
  rosidl_runtime_c__double__Sequence__fini(&msg->right_foot_contacts);
  // num_left_foot_contacts
  // left_foot_contacts
  rosidl_runtime_c__double__Sequence__fini(&msg->left_foot_contacts);
}

bool
pronto_msgs__msg__ControllerFootContact__are_equal(const pronto_msgs__msg__ControllerFootContact * lhs, const pronto_msgs__msg__ControllerFootContact * rhs)
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
  // num_right_foot_contacts
  if (lhs->num_right_foot_contacts != rhs->num_right_foot_contacts) {
    return false;
  }
  // right_foot_contacts
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->right_foot_contacts), &(rhs->right_foot_contacts)))
  {
    return false;
  }
  // num_left_foot_contacts
  if (lhs->num_left_foot_contacts != rhs->num_left_foot_contacts) {
    return false;
  }
  // left_foot_contacts
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->left_foot_contacts), &(rhs->left_foot_contacts)))
  {
    return false;
  }
  return true;
}

bool
pronto_msgs__msg__ControllerFootContact__copy(
  const pronto_msgs__msg__ControllerFootContact * input,
  pronto_msgs__msg__ControllerFootContact * output)
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
  // num_right_foot_contacts
  output->num_right_foot_contacts = input->num_right_foot_contacts;
  // right_foot_contacts
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->right_foot_contacts), &(output->right_foot_contacts)))
  {
    return false;
  }
  // num_left_foot_contacts
  output->num_left_foot_contacts = input->num_left_foot_contacts;
  // left_foot_contacts
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->left_foot_contacts), &(output->left_foot_contacts)))
  {
    return false;
  }
  return true;
}

pronto_msgs__msg__ControllerFootContact *
pronto_msgs__msg__ControllerFootContact__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__ControllerFootContact * msg = (pronto_msgs__msg__ControllerFootContact *)allocator.allocate(sizeof(pronto_msgs__msg__ControllerFootContact), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pronto_msgs__msg__ControllerFootContact));
  bool success = pronto_msgs__msg__ControllerFootContact__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pronto_msgs__msg__ControllerFootContact__destroy(pronto_msgs__msg__ControllerFootContact * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pronto_msgs__msg__ControllerFootContact__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pronto_msgs__msg__ControllerFootContact__Sequence__init(pronto_msgs__msg__ControllerFootContact__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__ControllerFootContact * data = NULL;

  if (size) {
    data = (pronto_msgs__msg__ControllerFootContact *)allocator.zero_allocate(size, sizeof(pronto_msgs__msg__ControllerFootContact), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pronto_msgs__msg__ControllerFootContact__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pronto_msgs__msg__ControllerFootContact__fini(&data[i - 1]);
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
pronto_msgs__msg__ControllerFootContact__Sequence__fini(pronto_msgs__msg__ControllerFootContact__Sequence * array)
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
      pronto_msgs__msg__ControllerFootContact__fini(&array->data[i]);
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

pronto_msgs__msg__ControllerFootContact__Sequence *
pronto_msgs__msg__ControllerFootContact__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pronto_msgs__msg__ControllerFootContact__Sequence * array = (pronto_msgs__msg__ControllerFootContact__Sequence *)allocator.allocate(sizeof(pronto_msgs__msg__ControllerFootContact__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pronto_msgs__msg__ControllerFootContact__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pronto_msgs__msg__ControllerFootContact__Sequence__destroy(pronto_msgs__msg__ControllerFootContact__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pronto_msgs__msg__ControllerFootContact__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pronto_msgs__msg__ControllerFootContact__Sequence__are_equal(const pronto_msgs__msg__ControllerFootContact__Sequence * lhs, const pronto_msgs__msg__ControllerFootContact__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pronto_msgs__msg__ControllerFootContact__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pronto_msgs__msg__ControllerFootContact__Sequence__copy(
  const pronto_msgs__msg__ControllerFootContact__Sequence * input,
  pronto_msgs__msg__ControllerFootContact__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pronto_msgs__msg__ControllerFootContact);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pronto_msgs__msg__ControllerFootContact * data =
      (pronto_msgs__msg__ControllerFootContact *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pronto_msgs__msg__ControllerFootContact__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pronto_msgs__msg__ControllerFootContact__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pronto_msgs__msg__ControllerFootContact__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
