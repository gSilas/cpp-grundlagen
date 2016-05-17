
cmake_minimum_required(VERSION 3.5)
project(dynamicobjectlist)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES object.cpp program.cpp object.h dynamicobjectlist.hpp dynamicobjectlist.cpp)
add_executable(ScopeTimerGuidline ${SOURCE_FILES})