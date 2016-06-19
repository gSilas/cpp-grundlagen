
cmake_minimum_required(VERSION 3.5)
project(logger)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES program.cpp filepolicy.cpp filepolicy.hpp logger.cpp logger.hpp policy.hpp consolepolicy.cpp consolepolicy.hpp)
add_executable(logger ${SOURCE_FILES})