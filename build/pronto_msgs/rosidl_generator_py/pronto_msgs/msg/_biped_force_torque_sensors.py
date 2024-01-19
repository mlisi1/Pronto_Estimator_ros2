# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pronto_msgs:msg/BipedForceTorqueSensors.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BipedForceTorqueSensors(type):
    """Metaclass of message 'BipedForceTorqueSensors'."""

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
                'pronto_msgs.msg.BipedForceTorqueSensors')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__biped_force_torque_sensors
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__biped_force_torque_sensors
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__biped_force_torque_sensors
            cls._TYPE_SUPPORT = module.type_support_msg__msg__biped_force_torque_sensors
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__biped_force_torque_sensors

            from geometry_msgs.msg import Wrench
            if Wrench.__class__._TYPE_SUPPORT is None:
                Wrench.__class__.__import_type_support__()

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


class BipedForceTorqueSensors(metaclass=Metaclass_BipedForceTorqueSensors):
    """Message class 'BipedForceTorqueSensors'."""

    __slots__ = [
        '_header',
        '_l_foot',
        '_r_foot',
        '_l_hand',
        '_r_hand',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'l_foot': 'geometry_msgs/Wrench',
        'r_foot': 'geometry_msgs/Wrench',
        'l_hand': 'geometry_msgs/Wrench',
        'r_hand': 'geometry_msgs/Wrench',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Wrench'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Wrench'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Wrench'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Wrench'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from geometry_msgs.msg import Wrench
        self.l_foot = kwargs.get('l_foot', Wrench())
        from geometry_msgs.msg import Wrench
        self.r_foot = kwargs.get('r_foot', Wrench())
        from geometry_msgs.msg import Wrench
        self.l_hand = kwargs.get('l_hand', Wrench())
        from geometry_msgs.msg import Wrench
        self.r_hand = kwargs.get('r_hand', Wrench())

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
        if self.l_foot != other.l_foot:
            return False
        if self.r_foot != other.r_foot:
            return False
        if self.l_hand != other.l_hand:
            return False
        if self.r_hand != other.r_hand:
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
    def l_foot(self):
        """Message field 'l_foot'."""
        return self._l_foot

    @l_foot.setter
    def l_foot(self, value):
        if __debug__:
            from geometry_msgs.msg import Wrench
            assert \
                isinstance(value, Wrench), \
                "The 'l_foot' field must be a sub message of type 'Wrench'"
        self._l_foot = value

    @builtins.property
    def r_foot(self):
        """Message field 'r_foot'."""
        return self._r_foot

    @r_foot.setter
    def r_foot(self, value):
        if __debug__:
            from geometry_msgs.msg import Wrench
            assert \
                isinstance(value, Wrench), \
                "The 'r_foot' field must be a sub message of type 'Wrench'"
        self._r_foot = value

    @builtins.property
    def l_hand(self):
        """Message field 'l_hand'."""
        return self._l_hand

    @l_hand.setter
    def l_hand(self, value):
        if __debug__:
            from geometry_msgs.msg import Wrench
            assert \
                isinstance(value, Wrench), \
                "The 'l_hand' field must be a sub message of type 'Wrench'"
        self._l_hand = value

    @builtins.property
    def r_hand(self):
        """Message field 'r_hand'."""
        return self._r_hand

    @r_hand.setter
    def r_hand(self, value):
        if __debug__:
            from geometry_msgs.msg import Wrench
            assert \
                isinstance(value, Wrench), \
                "The 'r_hand' field must be a sub message of type 'Wrench'"
        self._r_hand = value
