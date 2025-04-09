find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SRC_CORE 
    ${CMAKE_CURRENT_SOURCE_DIR}/engine/core/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/engine/core/*.c
)
file(GLOB_RECURSE SRC_GAMEPLAY 
    ${CMAKE_CURRENT_SOURCE_DIR}/engine/gameplay/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/engine/gameplay/*.c
)
file(GLOB_RECURSE SRC_GRAPHICS 
    ${CMAKE_CURRENT_SOURCE_DIR}/engine/graphics/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/engine/graphics/*.c
)
file(GLOB_RECURSE SRC_INPUT
    ${CMAKE_CURRENT_SOURCE_DIR}/engine/input/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/engine/input/*.c
)

add_library(LOLEngine STATIC
    main.cpp
    ${SRC_CORE}
    ${SRC_GRAPHICS}
    ${SRC_GAMEPLAY}
    ${SRC_INPUT}
)

target_include_directories(LOLEngine PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include/>
    $<INSTALL_INTERFACE:include>
)

target_include_directories(LOLEngine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/glfw/include
    ${OPENGL_INCLUDE_DIR}
)

# logging
add_library(spdlog INTERFACE)
target_include_directories(spdlog INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/spdlog/include>
    $<INSTALL_INTERFACE:include>
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)

target_link_libraries(LOLEngine PUBLIC 
    spdlog 
    glfw
    ${OPENGL_LIBRARIES}
)

if(APPLE)
    target_compile_definitions(LOLEngine PRIVATE GL_SILENCE_DEPRECATION)
endif()
