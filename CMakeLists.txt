cmake_minimum_required(VERSION 3.5)

add_definitions(-std=c++14)
add_definitions(-DNOMINMAX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(miasteczko)

enable_testing(true)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
file(GLOB DEBUG_DLLS "$ENV{SFML_ROOT}/bin/*-d-2.dll" $ENV{SFML_ROOT}/bin/openal32.dll)
file(GLOB RELEASE_DLLS "$ENV{SFML_ROOT}/bin/*[^-d]-2.dll" $ENV{SFML_ROOT}/bin/openal32.dll)

add_subdirectory(src)
add_subdirectory(tests)

