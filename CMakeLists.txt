cmake_minimum_required(VERSION 3.20)
project(vml)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/libs)
include_directories(${PROJECT_SOURCE_DIR}/include)
if (WIN32)
    link_directories(${PROJECT_SOURCE_DIR}/libs/windows)
elseif(UNIX)
    link_directories(${PROJECT_SOURCE_DIR}/libs/linux)
endif()

list(APPEND SOURCES
    main.c
)

add_executable(vml ${SOURCES})
target_link_libraries(vml -lvml)