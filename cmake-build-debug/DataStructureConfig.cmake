# Compute installation prefix relative to this file.
get_filename_component (_dir "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component (_prefix "${_dir}/../.." ABSOLUTE)
# Import the targets.
include ("${_prefix}/lib/DataStructure-1.0/DataStructure-1.0-targets.cmake")
# Report other information.
set (DataStructure_INCLUDE_DIRS "${_prefix}/include/DataStructure-1.0")
