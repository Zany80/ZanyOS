cmake_minimum_required(VERSION 3.0)

# Enable use of VERSION in project() command
cmake_policy(SET CMP0048 NEW)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# Enable assembly files
ENABLE_LANGUAGE(ASM-ATT)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

project(ZenithOS VERSION 0.1.0.0 LANGUAGES C CXX ASM-ATT)
include(git_revision)

# Read in config.h.in and create a valid CXX header in the build directory
configure_file(
  "${ZenithOS_SOURCE_DIR}/config.h.in"
  "${ZenithOS_BINARY_DIR}/config.h"
  )

# ZenithOS_BINARY_DIR is needed so config.h can be included
include_directories("${ZenithOS_BINARY_DIR}" "${ZenithOS_SOURCE_DIR}/headers")

add_subdirectory(src/kernel)
add_executable(zenithos.bin "${SOURCES}")
