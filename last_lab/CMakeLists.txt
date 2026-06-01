cmake_minimum_required(VERSION 3.10)
project(last_lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(last_lab main.cpp)

add_custom_command(TARGET last_lab POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/input.txt"
        "$<TARGET_FILE_DIR:last_lab>/input.txt"
)