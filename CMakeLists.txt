project(TimeDuration)
cmake_minimum_required(VERSION 2.6.2)
include_directories(${TimeDuration_SOURCE_DIR}/src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -o0")

add_executable(running_test ${TimeDuration_SOURCE_DIR}/sample/running_test.cpp)

