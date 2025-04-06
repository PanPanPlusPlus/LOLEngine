cmake_minimum_required(VERSION 3.20)
project(LOLTutorial VERSION 1.0 LANGUAGES CXX)

# Убрать генерацию тестовых target при сборке под IDE
set(CMAKE_SUPPRESS_REGENERATION true)
# Плюсы версии 23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем движок
add_subdirectory(LOLEngine)
# Подключаем исполняемый проект
add_subdirectory(Game)