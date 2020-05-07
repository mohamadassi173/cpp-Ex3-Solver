cmake_minimum_required(VERSION 3.16)
project(abd_elbari__)

set(CMAKE_CXX_STANDARD 20)

add_executable(abd_elbari__ Demo.cpp solver.hpp solver.cpp)