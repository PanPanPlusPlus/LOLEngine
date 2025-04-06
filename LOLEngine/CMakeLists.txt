# рекурсивно находим исходники
find_package(OpenGL REQUIRED)
file(GLOB_RECURSE ENGINE_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/Internal/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Internal/*.c
)

file(GLOB_RECURSE ENGINE_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Internal/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Internal/*.hpp
)

# подключаем их к проекту. проект движка - static library
add_library(LOLEngine STATIC 
	${ENGINE_SOURCES}
    ${ENGINE_HEADERS}
)

# сохраняем структуру каталогов для IDE
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} 
    FILES ${ENGINE_SOURCES} ${ENGINE_HEADERS}
)

# подключение собственных Include папок
target_include_directories(LOLEngine PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/Internal
)
# Include, которые будут видны проектам, которые подключат движок
target_include_directories(LOLEngine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/glm
	${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/glfw/include
    ${OPENGL_INCLUDE_DIR} 
)

# подключение glfw и glm к движку
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
target_link_libraries(LOLEngine PUBLIC
	glm
	glfw
    ${OPENGL_LIBRARIES}
)