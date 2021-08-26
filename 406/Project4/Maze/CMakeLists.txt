cmake_minimum_required(VERSION 3.17)
project(Maze)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.75.0 REQUIRED COMPONENTS filesystem)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(Maze main.cpp)