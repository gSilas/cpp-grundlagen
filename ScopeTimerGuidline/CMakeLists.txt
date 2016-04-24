
cmake_minimum_required(VERSION 3.5)
project(ScopeTimerGuidline)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES demo.cpp timer.cpp timer.hpp)
add_executable(ScopeTimerGuidline ${SOURCE_FILES})