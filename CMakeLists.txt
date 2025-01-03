cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled F/interpretator.cpp F/interpretator.h F/start.cpp main.cpp
        F/interLibrary/documentation.h
        F/interLibrary/documentation.cpp)
