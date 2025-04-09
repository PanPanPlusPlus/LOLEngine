file(GLOB_RECURSE GAME_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
)
file(GLOB_RECURSE GAME_HEADERS
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
)

add_executable(EmptyProject 
	${GAME_SOURCES}
    ${GAME_HEADERS}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} 
    FILES ${GAME_SOURCES} ${GAME_HEADERS}
)

target_include_directories(EmptyProject PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src/
	${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_link_libraries(EmptyProject LOLEngine)