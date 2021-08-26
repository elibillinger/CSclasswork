cmake_minimum_required(VERSION 3.17)
project(Project5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project5
        brute_model.cpp
        brute_model.h
        main.cpp
        map_model.cpp
        map_model.h
        markov.cpp
        markov.h
        model.h
        word_model.cpp
        word_model.h)
