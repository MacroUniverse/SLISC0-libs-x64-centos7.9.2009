#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cblas" for configuration "Release"
set_property(TARGET cblas APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(cblas PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "blas"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libcblas.so.3.10.1"
  IMPORTED_SONAME_RELEASE "libcblas.so.3"
  )

list(APPEND _cmake_import_check_targets cblas )
list(APPEND _cmake_import_check_files_for_cblas "${_IMPORT_PREFIX}/lib64/libcblas.so.3.10.1" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
