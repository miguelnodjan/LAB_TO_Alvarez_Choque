# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\paises_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\paises_autogen.dir\\ParseCache.txt"
  "paises_autogen"
  )
endif()
