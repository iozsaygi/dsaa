cmake_minimum_required(VERSION 3.26)
project(dsaa C)

set(CMAKE_C_STANDARD 23)

# Check if we are running on Windows based system.
if (WIN32)
    # Add a specific define symbol for Windows to enable usage of WINAPI.
    message(STATUS "Adding extra compile definitions for Windows")
    add_compile_definitions(DSAA_WINAPI)
endif ()

# Setting up options for MinGW based environment.
if (MINGW)
    message(STATUS "Adding extra compiler flags for MinGW")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
endif ()

# Setting up options for Clang based environment.
if (CMAKE_C_COMPILER_ID MATCHES "Clang")
    message(STATUS "Adding extra compiler flags for Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-newline-eof")
endif ()

add_executable(dsaa src/main.c
        src/fixed_size_array.c
        src/singly_linked_list.c
        src/dynamic_array.c
        src/stack.c
        src/queue.c
        src/linear_search.c
        src/binary_search.c
        src/selection_sort.c
        src/newton_sqrt.c
        src/bubble_sort.c
        src/floyd_tortoise_hare.c
        src/doubly_linked_list.c
        src/hash_table.c
        src/counting_sort.c
        src/binary_tree.c
        src/linear_congruential_generator.c
        src/sleep_sort.c
        src/quick_sort.c
        src/min_heap.c
        src/circular_singly_linked_list.c
        src/breadth_first_search.c)

include_directories(${CMAKE_SOURCE_DIR}/include)