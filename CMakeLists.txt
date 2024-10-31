cmake_minimum_required(VERSION 3.15)
project(inscribe-text-editor)

# Ställ in C++-standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Inkludera vcpkg-integrering om det finns
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

# Sökväg till FLTK
find_package(FLTK REQUIRED)

# Inkludera alla .cpp-filer som ingår i projektet
set(SOURCES
    src/main.cpp
    src/Window.cpp
    # Lägg till fler filer om nödvändigt
)

# Skapa exekverbara filen
add_executable(inscribe-text-editor ${SOURCES})

# Länka FLTK-biblioteket
target_link_libraries(inscribe-text-editor PRIVATE fltk)
