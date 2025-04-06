# рекурсивно находим все нужные исходники
file(GLOB_RECURSE GAME_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)
file(GLOB_RECURSE GAME_HEADERS
	${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

# цепляем не только cpp/c, но и hpp/h, чтобы они отображались в IDE
# имя пока ставлю Game, тип проекта - executable
add_executable(Game 
	${GAME_SOURCES}
    ${GAME_HEADERS}
)
# для IDE сохраняем структуру каталогов
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} 
    FILES ${GAME_SOURCES} ${GAME_HEADERS}
)

# Include папки из движка и из этого проекта
target_include_directories(Game PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/Sources
	${CMAKE_CURRENT_SOURCE_DIR}/../LOLEngine/Include
)

# подключаем библиотеки
target_link_libraries(Game LOLEngine)