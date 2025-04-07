cmake_minimum_required(VERSION 3.20)
project(LOLTutorial VERSION 1.0 LANGUAGES CXX)

set(CMAKE_SUPPRESS_REGENERATION true)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(LOLEngine)
add_subdirectory(Game)

