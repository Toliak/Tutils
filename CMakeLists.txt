cmake_minimum_required(VERSION 3.13)

project(BeautifulStream)

set(CMAKE_CXX_STANDARD 14)

set(
    BEAUTIFUL_STREAM_SOURCES
    main.cpp
    src/Stream.cpp
    src/Stream.h
    src/IOStream.cpp
    src/IOStream.h
    src/CachedStreamTree.cpp
    src/CachedStreamTree.h
    src/utilities.cpp
    src/utilities.h
    src/Tree.cpp
    src/Tree.h
    src/StreamTree.cpp
    src/StreamTree.h
)

add_executable(
        BeautifulStream
        ${BEAUTIFUL_STREAM_SOURCES}
)

add_library(
        BeautifulStreamLib
        ${BEAUTIFUL_STREAM_SOURCES}
)

add_executable(BeautifulStreamTest tests.cpp)

include_directories(gtest)
target_link_libraries(BeautifulStreamTest BeautifulStreamLib gtest gtest_main)