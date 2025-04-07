file(GLOB_RECURSE GAME_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)
file(GLOB_RECURSE GAME_HEADERS
	${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

add_executable(Game 
	${GAME_SOURCES}
    ${GAME_HEADERS}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} 
    FILES ${GAME_SOURCES} ${GAME_HEADERS}
)

target_include_directories(Game PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/Sources
	${CMAKE_CURRENT_SOURCE_DIR}/../LOLEngine/Include
)

target_link_libraries(Game LOLEngine)