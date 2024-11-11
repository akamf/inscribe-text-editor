cmake_minimum_required(VERSION 3.15)
project(inscribe-text-editor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(fmt CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

file(GLOB SOURCES
    src/*.cpp
    src/FileManager/*.cpp
    src/Utils/Logging/*.cpp
)

add_executable(inscribe-text-editor ${SOURCES})

target_link_libraries(inscribe-text-editor PRIVATE
    fmt::fmt
    imgui::imgui
    OpenGL::GL
    glfw
)
