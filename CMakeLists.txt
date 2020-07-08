cmake_minimum_required(VERSION 3.5)

project(bulky)

add_executable(bulk observer.h observer.cpp main.cpp)

set_target_properties(bulk PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wall;-Wpedantic;-Wextra"
)