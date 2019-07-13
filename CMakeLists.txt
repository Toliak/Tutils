cmake_minimum_required(VERSION 3.0)

project(BeautifulStream)

set(CMAKE_CXX_STANDARD 14)

option(BUILD_TESTS Off "Build tests")

set(
        ${PROJECT_NAME}_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Stream.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/IOStream.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/CachedStreamTree.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/utilities.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Tree.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/StreamTree.cpp
)

add_library(
        ${PROJECT_NAME}
        STATIC
        ${${PROJECT_NAME}_SOURCE}
)

set(
        ${PROJECT_NAME}_INCLUDE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include_directories(${${PROJECT_NAME}_INCLUDE})

target_include_directories(${PROJECT_NAME} SYSTEM INTERFACE
        "$<BUILD_INTERFACE:${${PROJECT_NAME}_INCLUDE}>")

if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(lib/gtest)

    file(GLOB ${PROJECT_NAME}_TESTS_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
    add_executable(${PROJECT_NAME}Test ${${PROJECT_NAME}_TESTS_SOURCE})
    target_link_libraries(${PROJECT_NAME}Test gtest)

    add_test(NAME ${PROJECT_NAME}Test COMMAND ${PROJECT_NAME}Test)
endif()