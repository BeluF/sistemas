# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/clase31-03-25_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/clase31-03-25_autogen.dir/ParseCache.txt"
  "clase31-03-25_autogen"
  )
endif()
