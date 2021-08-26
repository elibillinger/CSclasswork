cmake_minimum_required(VERSION 3.17)
project(lab12)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab12 tests.cpp unix_clock.cpp unix_clock.h analog_clock.h)