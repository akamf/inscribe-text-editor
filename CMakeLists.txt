cmake_minimum_required(VERSION 3.15)
project(inscribe-text-editor)

# C++-standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# vcpkg-integration (if used)
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

# Project .cpp-files
set(SOURCES
    src/main.cpp
    src/FileManager/FileManager.cpp
    # src/Window.cpp
    # Add more as needed
)

add_executable(inscribe-text-editor ${SOURCES})

# Länka FLTK-biblioteket
target_link_libraries(inscribe-text-editor PRIVATE fltk)
