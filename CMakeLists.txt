cmake_minimum_required(VERSION 2.8.8)

project(BeautifulStream)

set(CMAKE_CXX_STANDARD 14)

add_library(
        BeautifulStream
        src/Stream.cpp
        src/IOStream.cpp
        src/CachedStreamTree.cpp
        src/utilities.cpp
        src/Tree.cpp
        src/StreamTree.cpp
)

set(BeautifulStreamInclude "${CMAKE_CURRENT_SOURCE_DIR}/include")

include_directories(${BeautifulStreamInclude})

target_include_directories(BeautifulStream SYSTEM INTERFACE
        "$<BUILD_INTERFACE:${BeautifulStreamInclude}>")