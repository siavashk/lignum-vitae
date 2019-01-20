cmake_minimum_required(VERSION 3.8.2)

project(lignumvitae)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

include("build/PrecompiledHeader.cmake")

add_subdirectory(core)

add_subdirectory(examples)
