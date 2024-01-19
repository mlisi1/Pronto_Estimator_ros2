#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "pronto_quadruped::pronto_quadruped" for configuration ""
set_property(TARGET pronto_quadruped::pronto_quadruped APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(pronto_quadruped::pronto_quadruped PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libpronto_quadruped.so"
  IMPORTED_SONAME_NOCONFIG "libpronto_quadruped.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS pronto_quadruped::pronto_quadruped )
list(APPEND _IMPORT_CHECK_FILES_FOR_pronto_quadruped::pronto_quadruped "${_IMPORT_PREFIX}/lib/libpronto_quadruped.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
