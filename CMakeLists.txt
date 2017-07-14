cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(miasteczko)

enable_testing(true)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
file(GLOB_RECURSE LibFiles "include/*.hpp")
add_custom_target(headers SOURCES ${LibFiles})

# Define sources and executable
set(EXECUTABLE_NAME "miasteczko")
add_executable(${EXECUTABLE_NAME} ${SOURCES} main.cpp)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

# Make test executable
file(GLOB TESTS "tests/*.cpp")
add_executable(miasteczkoUT ${SOURCES} ${TESTS})
target_link_libraries(miasteczkoUT ${SFML_LIBRARIES})





