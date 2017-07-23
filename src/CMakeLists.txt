include_directories(../include)
file(GLOB_RECURSE SOURCES "*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(EXECUTABLE_NAME "miasteczko")

add_executable(${EXECUTABLE_NAME} ${SOURCES})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
