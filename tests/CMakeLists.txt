include_directories(../include)
file(GLOB_RECURSE TESTS "*.cpp")
file(GLOB_RECURSE SOURCES "../src/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/../src/main.cpp")

set(EXECUTABLE_NAME "miasteczko-ut-tests")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin-tests")

add_executable(${EXECUTABLE_NAME} ${SOURCES} ${TESTS})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})