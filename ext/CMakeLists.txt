# Find required libraries
find_package(X11  REQUIRED)
find_package(ZLIB  REQUIRED)

# =======================================
# ============== json ===================
add_library(json INTERFACE)
target_include_directories(json INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/json/)

# =======================================
# ============== ECS ====================
add_library(ecs INTERFACE)
target_include_directories(json INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/ECS/)

# =======================================
# =========== BearLibTerminal ===========
add_subdirectory(BearLibTerminal/Terminal)
set(BearLibTerminal_IncludeDir BearLibTerminal/Terminal/Include/C)
