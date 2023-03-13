cmake_minimum_required(VERSION 3.20)
project(vml)

# set(CMAKE_SYSTEM_NAME WIN32)
# set(WIN32 TRUE)
set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/objs)
include_directories(${PROJECT_SOURCE_DIR}/include)

if(WIN32)
    set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
    set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
    set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin/windows)
    SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/windows)
    SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/windows)
    link_directories(${PROJECT_SOURCE_DIR}/libs/windows)
elseif(LINUX)
    set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin/linux)
    SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/linux)
    SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/linux)
    link_directories(${PROJECT_SOURCE_DIR}/libs/linux)
elseif(UNIX)
    set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin/linux)
    SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/linux)
    SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/linux)
    link_directories(${PROJECT_SOURCE_DIR}/libs/linux)
endif()

list(APPEND MAIN
    main.c
)

list(APPEND SOURCES
    src/matrix.c
    src/vml.c
    src/vector.c
)

set(LIBNAME "vml")
set(LIBNAME_OBJ "${LIBNAME}_obj")

add_library(${LIBNAME_OBJ} OBJECT ${SOURCES})

target_include_directories(${LIBNAME_OBJ} PUBLIC "include")
target_compile_options(${LIBNAME_OBJ} PUBLIC "-fPIC")

add_library(${LIBNAME} SHARED $<TARGET_OBJECTS:${LIBNAME_OBJ}>)

set(OBJ_DIR ${PROJECT_SOURCE_DIR}/objs)

add_custom_command(TARGET ${LIBNAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${OBJ_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_OBJECTS:${LIBNAME_OBJ}> ${OBJ_DIR})
add_executable(vmltest ${MAIN})
target_link_libraries(vmltest -lvml)