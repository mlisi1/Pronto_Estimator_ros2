#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "pronto_ros::pronto_ros" for configuration ""
set_property(TARGET pronto_ros::pronto_ros APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(pronto_ros::pronto_ros PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libpronto_ros.so"
  IMPORTED_SONAME_NOCONFIG "libpronto_ros.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS pronto_ros::pronto_ros )
list(APPEND _IMPORT_CHECK_FILES_FOR_pronto_ros::pronto_ros "${_IMPORT_PREFIX}/lib/libpronto_ros.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
