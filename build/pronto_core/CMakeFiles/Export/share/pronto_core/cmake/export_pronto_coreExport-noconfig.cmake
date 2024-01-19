#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "pronto_core::pronto_core" for configuration ""
set_property(TARGET pronto_core::pronto_core APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(pronto_core::pronto_core PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libpronto_core.so"
  IMPORTED_SONAME_NOCONFIG "libpronto_core.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS pronto_core::pronto_core )
list(APPEND _IMPORT_CHECK_FILES_FOR_pronto_core::pronto_core "${_IMPORT_PREFIX}/lib/libpronto_core.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
