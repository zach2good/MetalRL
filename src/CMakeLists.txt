set(SOURCES
        main.cpp
        common.h
        Engine.cpp
        Engine.h)

set(RESOURCES
        ${CMAKE_SOURCE_DIR}/res/terminal.png)

add_executable(MetalRL ${SOURCES} ${RESOURCES})

target_link_libraries(MetalRL PUBLIC tcod tcodxx)
target_include_directories(MetalRL PUBLIC ${CMAKE_BINARY_DIR}/generated/)

set_target_properties(MetalRL PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_FRAMEWORK_IDENTIFIER org.cmake.ExecutableTarget
        RESOURCE "${RESOURCES}"
        )

