cmake_minimum_required(VERSION 3.9)
project(DataStructuresInCpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER /usr/bin/g++)
set(CMAKE_CXX_COMPILER  /usr/bin/g++)

add_executable(DataStructuresInCpp main.cpp List/list.h)