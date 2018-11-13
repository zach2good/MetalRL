cmake_minimum_required(VERSION 3.12)
project(MetalRL)
set(CMAKE_CXX_STANDARD 17)

# cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake-modules)

# when building, put the executable in the root directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(${CMAKE_SOURCE_DIR}/ext)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
