
cmake_minimum_required(VERSION 3.5)
project(hybridarray)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES program.cpp hybridarray.hpp)
add_executable(hybridarray ${SOURCE_FILES})