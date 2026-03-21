cmake_minimum_required(VERSION 3.11)

# 1. Project Name
project(CircularDoublyLinkedList C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 5. Define the executable and the source files needed to build it
add_executable(CircularDoublyLinkedList 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c" 
    "${CMAKE_CURRENT_SOURCE_DIR}/implementation/doubly_circular_list.c" 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/doubly_circular_list.h"
)