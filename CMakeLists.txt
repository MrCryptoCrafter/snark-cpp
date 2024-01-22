cmake_minimum_required(VERSION 3.10)
project(ZKSNARKS)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Find GMP using PkgConfig
find_package(PkgConfig REQUIRED)
pkg_check_modules(gmp REQUIRED IMPORTED_TARGET gmp)

# Define your source files here
set(SOURCES
    src/test.cpp
)

# Add the executable
add_executable(ZKSNARKS ${SOURCES})

# Include directories
target_include_directories(ZKSNARKS PRIVATE include)

# Link the GMP library
target_link_libraries(ZKSNARKS PkgConfig::gmp)

# Set VS_STARTUP_PROJECT for Visual Studio users
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ZKSNARKS)

# Debug configuration
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
