cmake_minimum_required(VERSION 3.24)
project(SList C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(SList
        SList.c
        SList.h test.c)
