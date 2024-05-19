cmake_minimum_required (VERSION 3.12.0)
project(NIT_TDD)

find_package(GTest REQUIRED)

add_subdirectory(src)
add_subdirectory(mock)
add_subdirectory(test)
