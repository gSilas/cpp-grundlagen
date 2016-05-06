
cmake_minimum_required(VERSION 3.5)
project(dynamicobjectlist)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES program.cpp RandomChar.cpp RandomChar.h TestObject.cpp TestObject.h)
add_executable(ScopeTimerGuidline ${SOURCE_FILES})