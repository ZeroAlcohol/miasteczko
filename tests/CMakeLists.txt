include_directories(../include)
file(GLOB_RECURSE TESTS "*.cpp")
file(GLOB_RECURSE SOURCES "../src/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/../src/main.cpp")

set(EXECUTABLE_TESTS_NAME "miasteczko-ut-tests")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin-tests")

find_path(CATCH_INCLUDE_DIR catch.hpp
          PATH_SUFFIXES single_include
          PATHS ${CMAKE_SOURCE_DIR}/external/Catch)

if((NOT CATCH_INCLUDE_DIR) OR (NOT EXISTS ${CATCH_INCLUDE_DIR}))
	execute_process(COMMAND git submodule update --init -- external/Catch
                    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
	set(CATCH_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/Catch/single_include)
endif()

include_directories(${CATCH_INCLUDE_DIR})

add_executable(${EXECUTABLE_TESTS_NAME} ${SOURCES} ${TESTS})
target_link_libraries(${EXECUTABLE_TESTS_NAME} ${SFML_LIBRARIES})

if(WIN32) 
	if(MSVC)
		set_target_properties(${EXECUTABLE_TESTS_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug)
		file(COPY ${DEBUG_DLLS} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug)
		file(COPY ${RELEASE_DLLS} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Release)
	endif()
endif()
