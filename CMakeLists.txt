cmake_minimum_required(VERSION 3.0.0)
project(STUFF VERSION 0.1.0)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(source)
add_subdirectory(programs)