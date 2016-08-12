cmake_minimum_required(VERSION 3.5)
project(ContactDirectory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Hash.cpp Hash.h)
add_executable(ContactDirectory ${SOURCE_FILES})