cmake_minimum_required(VERSION 3.10)
project(Chapter5)

include_directories(include)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-DLOCAL)
add_executable(UVa10474 UVa10474_Where_is_the_Marble.cpp)
