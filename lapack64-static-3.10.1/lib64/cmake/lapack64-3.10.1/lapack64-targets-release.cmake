#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "blas64" for configuration "Release"
set_property(TARGET blas64 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(blas64 PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "Fortran"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libblas64.a"
  )

list(APPEND _cmake_import_check_targets blas64 )
list(APPEND _cmake_import_check_files_for_blas64 "${_IMPORT_PREFIX}/lib64/libblas64.a" )

# Import target "lapack64" for configuration "Release"
set_property(TARGET lapack64 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(lapack64 PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "Fortran"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/liblapack64.a"
  )

list(APPEND _cmake_import_check_targets lapack64 )
list(APPEND _cmake_import_check_files_for_lapack64 "${_IMPORT_PREFIX}/lib64/liblapack64.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
