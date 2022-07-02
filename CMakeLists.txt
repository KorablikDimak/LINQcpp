cmake_minimum_required(VERSION 3.22)
project(LINQcpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(LINQcpp main.cpp algorithm.h algorithmTests.cpp algorithmTests.h LINQ.h)
