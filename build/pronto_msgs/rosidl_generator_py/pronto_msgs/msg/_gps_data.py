# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pronto_msgs:msg/GPSData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'xyz_pos'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GPSData(type):
    """Metaclass of message 'GPSData'."""

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
                'pronto_msgs.msg.GPSData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gps_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gps_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gps_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gps_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gps_data

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


class GPSData(metaclass=Metaclass_GPSData):
    """Message class 'GPSData'."""

    __slots__ = [
        '_header',
        '_utime',
        '_gps_lock',
        '_longitude',
        '_latitude',
        '_elev',
        '_horizontal_accuracy',
        '_vertical_accuracy',
        '_num_satellites',
        '_speed',
        '_heading',
        '_xyz_pos',
        '_gps_time',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'utime': 'uint64',
        'gps_lock': 'int32',
        'longitude': 'double',
        'latitude': 'double',
        'elev': 'double',
        'horizontal_accuracy': 'double',
        'vertical_accuracy': 'double',
        'num_satellites': 'uint32',
        'speed': 'double',
        'heading': 'double',
        'xyz_pos': 'double[3]',
        'gps_time': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 3),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.utime = kwargs.get('utime', int())
        self.gps_lock = kwargs.get('gps_lock', int())
        self.longitude = kwargs.get('longitude', float())
        self.latitude = kwargs.get('latitude', float())
        self.elev = kwargs.get('elev', float())
        self.horizontal_accuracy = kwargs.get('horizontal_accuracy', float())
        self.vertical_accuracy = kwargs.get('vertical_accuracy', float())
        self.num_satellites = kwargs.get('num_satellites', int())
        self.speed = kwargs.get('speed', float())
        self.heading = kwargs.get('heading', float())
        if 'xyz_pos' not in kwargs:
            self.xyz_pos = numpy.zeros(3, dtype=numpy.float64)
        else:
            self.xyz_pos = numpy.array(kwargs.get('xyz_pos'), dtype=numpy.float64)
            assert self.xyz_pos.shape == (3, )
        self.gps_time = kwargs.get('gps_time', float())

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
        if self.gps_lock != other.gps_lock:
            return False
        if self.longitude != other.longitude:
            return False
        if self.latitude != other.latitude:
            return False
        if self.elev != other.elev:
            return False
        if self.horizontal_accuracy != other.horizontal_accuracy:
            return False
        if self.vertical_accuracy != other.vertical_accuracy:
            return False
        if self.num_satellites != other.num_satellites:
            return False
        if self.speed != other.speed:
            return False
        if self.heading != other.heading:
            return False
        if all(self.xyz_pos != other.xyz_pos):
            return False
        if self.gps_time != other.gps_time:
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
    def gps_lock(self):
        """Message field 'gps_lock'."""
        return self._gps_lock

    @gps_lock.setter
    def gps_lock(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gps_lock' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'gps_lock' field must be an integer in [-2147483648, 2147483647]"
        self._gps_lock = value

    @builtins.property
    def longitude(self):
        """Message field 'longitude'."""
        return self._longitude

    @longitude.setter
    def longitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'longitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'longitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._longitude = value

    @builtins.property
    def latitude(self):
        """Message field 'latitude'."""
        return self._latitude

    @latitude.setter
    def latitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'latitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'latitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._latitude = value

    @builtins.property
    def elev(self):
        """Message field 'elev'."""
        return self._elev

    @elev.setter
    def elev(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'elev' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'elev' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._elev = value

    @builtins.property
    def horizontal_accuracy(self):
        """Message field 'horizontal_accuracy'."""
        return self._horizontal_accuracy

    @horizontal_accuracy.setter
    def horizontal_accuracy(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'horizontal_accuracy' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'horizontal_accuracy' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._horizontal_accuracy = value

    @builtins.property
    def vertical_accuracy(self):
        """Message field 'vertical_accuracy'."""
        return self._vertical_accuracy

    @vertical_accuracy.setter
    def vertical_accuracy(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vertical_accuracy' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vertical_accuracy' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vertical_accuracy = value

    @builtins.property
    def num_satellites(self):
        """Message field 'num_satellites'."""
        return self._num_satellites

    @num_satellites.setter
    def num_satellites(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_satellites' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'num_satellites' field must be an unsigned integer in [0, 4294967295]"
        self._num_satellites = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed = value

    @builtins.property
    def heading(self):
        """Message field 'heading'."""
        return self._heading

    @heading.setter
    def heading(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'heading' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'heading' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._heading = value

    @builtins.property
    def xyz_pos(self):
        """Message field 'xyz_pos'."""
        return self._xyz_pos

    @xyz_pos.setter
    def xyz_pos(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'xyz_pos' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 3, \
                "The 'xyz_pos' numpy.ndarray() must have a size of 3"
            self._xyz_pos = value
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
                 len(value) == 3 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'xyz_pos' field must be a set or sequence with length 3 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._xyz_pos = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def gps_time(self):
        """Message field 'gps_time'."""
        return self._gps_time

    @gps_time.setter
    def gps_time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gps_time' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'gps_time' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._gps_time = value
