# cmake_minimum_required(VERSION <specify CMake version here>)
project(roadtocpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(roadtocpp first.c myfirst.cpp myfirst.h dynamic/dynamic.cpp)
add_executable(187 question187.cpp)