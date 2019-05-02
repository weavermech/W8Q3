cmake_minimum_required(VERSION 3.12)
project(Q3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Q3
        ex3.cpp
        LList.h
        LList.tcc
        StringC.cpp
        StringC.h
        mymin.h
        myswap.h)
