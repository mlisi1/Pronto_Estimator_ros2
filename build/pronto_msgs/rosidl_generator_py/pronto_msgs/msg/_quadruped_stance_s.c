// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from pronto_msgs:msg/QuadrupedStance.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "pronto_msgs/msg/detail/quadruped_stance__struct.h"
#include "pronto_msgs/msg/detail/quadruped_stance__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool pronto_msgs__msg__quadruped_stance__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("pronto_msgs.msg._quadruped_stance.QuadrupedStance", full_classname_dest, 49) == 0);
  }
  pronto_msgs__msg__QuadrupedStance * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // lf
    PyObject * field = PyObject_GetAttrString(_pymsg, "lf");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->lf = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rf
    PyObject * field = PyObject_GetAttrString(_pymsg, "rf");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rf = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // lh
    PyObject * field = PyObject_GetAttrString(_pymsg, "lh");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->lh = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rh
    PyObject * field = PyObject_GetAttrString(_pymsg, "rh");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rh = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * pronto_msgs__msg__quadruped_stance__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of QuadrupedStance */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("pronto_msgs.msg._quadruped_stance");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "QuadrupedStance");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  pronto_msgs__msg__QuadrupedStance * ros_message = (pronto_msgs__msg__QuadrupedStance *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lf
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->lf);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lf", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rf
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rf);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rf", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lh
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->lh);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lh", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rh
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rh);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rh", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
