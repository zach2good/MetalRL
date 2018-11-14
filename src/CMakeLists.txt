set(SOURCES
        ${CMAKE_SOURCE_DIR}/src/main.cpp
        ${CMAKE_SOURCE_DIR}/src/Engine.cpp
        ${CMAKE_SOURCE_DIR}/src/Engine.h
        ${CMAKE_SOURCE_DIR}/src/Map.cpp
        ${CMAKE_SOURCE_DIR}/src/Map.h
        ${CMAKE_SOURCE_DIR}/src/Log.cpp
        ${CMAKE_SOURCE_DIR}/src/Log.h
        ${CMAKE_SOURCE_DIR}/src/Actor.cpp
        ${CMAKE_SOURCE_DIR}/src/Actor.h)

set(RESOURCES
        ${CMAKE_SOURCE_DIR}/res/version.h)

add_executable(MetalRL MACOSX_BUNDLE ${SOURCES} ${RESOURCES})

target_link_libraries(MetalRL PUBLIC json BearLibTerminal)
target_include_directories(MetalRL PUBLIC
        ${CMAKE_SOURCE_DIR}/res/
        ${CMAKE_SOURCE_DIR}/src/
        ${CMAKE_SOURCE_DIR}/ext/BearLibTerminal/Terminal/Include/C/
        )

add_custom_target(WriteVersionInformation
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMAND bash ${CMAKE_SOURCE_DIR}/write_version_h.sh ${CMAKE_SOURCE_DIR}/res/version.h)
add_dependencies(MetalRL WriteVersionInformation)
