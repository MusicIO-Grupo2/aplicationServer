#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "mongoose" for configuration "Debug"
set_property(TARGET mongoose APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(mongoose PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "dl"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libmongoose.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS mongoose )
list(APPEND _IMPORT_CHECK_FILES_FOR_mongoose "${_IMPORT_PREFIX}/lib/libmongoose.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
