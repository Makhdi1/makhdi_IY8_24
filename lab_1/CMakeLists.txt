cmake_minimum_required(VERSION 3.10)
project(StringProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(string_demo
        main.cpp
        string.cpp
)

target_include_directories(string_demo PRIVATE .)
