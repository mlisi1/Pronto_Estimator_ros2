# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pronto_msgs:msg/IndexedMeasurement.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'z_effective'
# Member 'z_indices'
# Member 'r_effective'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_IndexedMeasurement(type):
    """Metaclass of message 'IndexedMeasurement'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('pronto_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'pronto_msgs.msg.IndexedMeasurement')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__indexed_measurement
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__indexed_measurement
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__indexed_measurement
            cls._TYPE_SUPPORT = module.type_support_msg__msg__indexed_measurement
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__indexed_measurement

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class IndexedMeasurement(metaclass=Metaclass_IndexedMeasurement):
    """Message class 'IndexedMeasurement'."""

    __slots__ = [
        '_header',
        '_utime',
        '_state_utime',
        '_z_effective',
        '_z_indices',
        '_r_effective',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'utime': 'uint64',
        'state_utime': 'uint64',
        'z_effective': 'sequence<double>',
        'z_indices': 'sequence<int32>',
        'r_effective': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.utime = kwargs.get('utime', int())
        self.state_utime = kwargs.get('state_utime', int())
        self.z_effective = array.array('d', kwargs.get('z_effective', []))
        self.z_indices = array.array('i', kwargs.get('z_indices', []))
        self.r_effective = array.array('d', kwargs.get('r_effective', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.utime != other.utime:
            return False
        if self.state_utime != other.state_utime:
            return False
        if self.z_effective != other.z_effective:
            return False
        if self.z_indices != other.z_indices:
            return False
        if self.r_effective != other.r_effective:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def utime(self):
        """Message field 'utime'."""
        return self._utime

    @utime.setter
    def utime(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utime' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'utime' field must be an unsigned integer in [0, 18446744073709551615]"
        self._utime = value

    @builtins.property
    def state_utime(self):
        """Message field 'state_utime'."""
        return self._state_utime

    @state_utime.setter
    def state_utime(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state_utime' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'state_utime' field must be an unsigned integer in [0, 18446744073709551615]"
        self._state_utime = value

    @builtins.property
    def z_effective(self):
        """Message field 'z_effective'."""
        return self._z_effective

    @z_effective.setter
    def z_effective(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'z_effective' array.array() must have the type code of 'd'"
            self._z_effective = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'z_effective' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._z_effective = array.array('d', value)

    @builtins.property
    def z_indices(self):
        """Message field 'z_indices'."""
        return self._z_indices

    @z_indices.setter
    def z_indices(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'z_indices' array.array() must have the type code of 'i'"
            self._z_indices = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'z_indices' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._z_indices = array.array('i', value)

    @builtins.property
    def r_effective(self):
        """Message field 'r_effective'."""
        return self._r_effective

    @r_effective.setter
    def r_effective(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'r_effective' array.array() must have the type code of 'd'"
            self._r_effective = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'r_effective' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._r_effective = array.array('d', value)
