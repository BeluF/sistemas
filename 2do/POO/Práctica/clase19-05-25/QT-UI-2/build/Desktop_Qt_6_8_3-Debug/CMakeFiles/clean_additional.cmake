# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QT-UI-2_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QT-UI-2_autogen.dir/ParseCache.txt"
  "QT-UI-2_autogen"
  )
endif()
