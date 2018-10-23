set(SOURCES
        main.cpp
        common.h
        Engine.cpp
        Engine.h)

add_executable(MetalRL ${SOURCES})

target_link_libraries(MetalRL PUBLIC tcod tcodxx)

target_include_directories(MetalRL PUBLIC ${CMAKE_BINARY_DIR}/generated/)