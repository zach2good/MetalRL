set(SOURCES
        main.cpp
        common.h
        Engine.cpp
        Engine.h)

set(RESOURCES
        ${CMAKE_SOURCE_DIR}/res/terminal.png
        ${CMAKE_SOURCE_DIR}/res/version.h)

add_executable(MetalRL MACOSX_BUNDLE ${SOURCES} ${RESOURCES})

target_link_libraries(MetalRL PUBLIC tcod tcodxx)
target_include_directories(MetalRL PUBLIC ${CMAKE_SOURCE_DIR}/res/)

set_target_properties(MetalRL PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_FRAMEWORK_IDENTIFIER org.cmake.ExecutableTarget
        RESOURCE "${RESOURCES}"
        )

add_custom_target(WriteVersionInformation
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMAND bash ${CMAKE_SOURCE_DIR}/write_version_h.sh ${CMAKE_SOURCE_DIR}/res/version.h)
add_dependencies(MetalRL WriteVersionInformation)
