cmake_minimum_required(VERSION 3.20)
project(SP_box)

set(CMAKE_CXX_STANDARD 17)

add_executable(SP_box main.cpp
        SPbox.cpp
        SPbox.h)
