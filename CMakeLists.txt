cmake_minimum_required(VERSION 3.12)

project(
    task_scheduler
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)

include_directories(lib)

add_subdirectory(bin)
