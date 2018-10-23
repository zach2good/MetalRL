# Find required libraries
find_package(X11  REQUIRED)
find_package(ZLIB  REQUIRED)

# =======================================
# ============== SDL2 ===================
set(SDL_SHARED OFF)
add_subdirectory(SDL2)
set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL2/include)

# =======================================
# ============== vendor =================
# glad
add_library(glad STATIC ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/vendor/glad.c)
target_include_directories(glad
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/vendor/
        ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/vendor/glad)

# KHR
add_library(khr INTERFACE)
target_include_directories(khr INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/vendor/KHR/)

# utf8proc
add_library(utf8proc STATIC ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/vendor/utf8proc/utf8proc.c)

# zlib defined above

# lodepng
add_library(lodepng STATIC ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/vendor/lodepng.cpp)
target_include_directories(lodepng
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/vendor/)

# stb
add_library(stb STATIC ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/vendor/stb.c)
target_include_directories(stb
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/vendor/)

# =======================================
# ============== libtcod ================
set(C_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/libtcod_c.c)

add_library(tcod
        STATIC
        ${C_SOURCES})

target_link_libraries(tcod
        PUBLIC
        glad
        khr
        utf8proc
        lodepng
        stb
        SDL2
        ${X11_LIBRARIES}
        ${ZLIB_LIBRARIES})

target_include_directories(tcod
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/
        ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/vendor/
        ${SDL2_INCLUDE_DIR}
        ${ZLIB_INCLUDE_DIR}
        ${X11_INCLUDE_DIR})

target_compile_options(tcod
        PRIVATE
        -Wno-deprecated-declarations
        -Wno-implicit-function-declaration)

# =======================================
# ============== libtcodxx ==============
set(CXX_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/libtcod.cpp)

add_library(tcodxx
        STATIC
        ${CXX_SOURCES})

target_link_libraries(tcodxx
        PUBLIC
        glad
        khr
        utf8proc
        lodepng
        stb
        SDL2
        ${X11_LIBRARIES}
        ${ZLIB_LIBRARIES})

target_include_directories(tcodxx
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/
        ${CMAKE_CURRENT_SOURCE_DIR}/libtcod/src/vendor/
        ${SDL2_INCLUDE_DIR}
        ${ZLIB_INCLUDE_DIR}
        ${X11_INCLUDE_DIR})

target_compile_definitions(tcodxx PUBLIC TCOD_SDL2)

target_compile_options(tcodxx
        PRIVATE
        -Wno-deprecated-declarations
        -Wno-writable-strings
        -Wno-implicit-exception-spec-mismatch
        -Wno-bitwise-op-parentheses)
