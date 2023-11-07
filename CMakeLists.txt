cmake_minimum_required(VERSION 3.26)
project(dsaa C)

set(CMAKE_C_STANDARD 23)

# Setting up options for Clang based environment.
if (CMAKE_C_COMPILER_ID MATCHES "Clang")
    message(STATUS "Adding extra compiler flags for Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-newline-eof")
endif ()

add_executable(dsaa src/main.c
        src/fixed_size_array.c)

include_directories(${CMAKE_SOURCE_DIR}/include)