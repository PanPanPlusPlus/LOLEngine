cmake_minimum_required(VERSION 3.20)
project(LOLEngine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_SUPPRESS_REGENERATION true)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENGINE_BUILD_EXAMPLES "Build examples" ON)

add_subdirectory(src)

if(ENGINE_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
