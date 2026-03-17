cmake_minimum_required(VERSION 3.10)

# 1. Project Name
project(CircularLinkedList C)

# 2. Set C Standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 3. Handle Visual Studio "Unsafe" warnings (scanf)
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# 4. Include the current directory so it can find circularlinkedlist.h
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 5. Define the executable and the source files needed to build it
add_executable(CircularLinkedList 
    "${CMAKE_CURRENT_SOURCE_DIR}/main.c" 
    "${CMAKE_CURRENT_SOURCE_DIR}/circularlinkedlist.c" 
    "${CMAKE_CURRENT_SOURCE_DIR}/circularlinkedlist.h"
)