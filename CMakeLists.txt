cmake_minimum_required(VERSION 3.17)
project(untitled)

include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled hypocycloid.cpp hypocycloid.h Prog2main.cpp)

add_subdirectory(lib/googletest-master)
target_link_libraries(untitled gtest gtest_main)

