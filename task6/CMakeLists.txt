
cmake_minimum_required(VERSION 3.5)
project(newdynamicobjectlist)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES node.cpp operators.cpp valuenode.cpp program.cpp valuenode.hpp node.hpp operators.cpp)
add_executable(ScopeTimerGuidline ${SOURCE_FILES})