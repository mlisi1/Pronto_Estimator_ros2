#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "pronto_utils::pronto_utils" for configuration ""
set_property(TARGET pronto_utils::pronto_utils APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(pronto_utils::pronto_utils PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libpronto_utils.so"
  IMPORTED_SONAME_NOCONFIG "libpronto_utils.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS pronto_utils::pronto_utils )
list(APPEND _IMPORT_CHECK_FILES_FOR_pronto_utils::pronto_utils "${_IMPORT_PREFIX}/lib/libpronto_utils.so" )

# Import target "pronto_utils::kalman_filter" for configuration ""
set_property(TARGET pronto_utils::kalman_filter APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(pronto_utils::kalman_filter PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libkalman_filter.so"
  IMPORTED_SONAME_NOCONFIG "libkalman_filter.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS pronto_utils::kalman_filter )
list(APPEND _IMPORT_CHECK_FILES_FOR_pronto_utils::kalman_filter "${_IMPORT_PREFIX}/lib/libkalman_filter.so" )

# Import target "pronto_utils::backlash_filter" for configuration ""
set_property(TARGET pronto_utils::backlash_filter APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(pronto_utils::backlash_filter PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libbacklash_filter.so"
  IMPORTED_SONAME_NOCONFIG "libbacklash_filter.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS pronto_utils::backlash_filter )
list(APPEND _IMPORT_CHECK_FILES_FOR_pronto_utils::backlash_filter "${_IMPORT_PREFIX}/lib/libbacklash_filter.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
