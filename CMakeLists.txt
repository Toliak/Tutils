cmake_minimum_required(VERSION 2.8.8)

project(BeautifulStreamLib)

set(CMAKE_CXX_STANDARD 14)

add_library(
        BeautifulStreamLib
        Stream.cpp
        Stream.h
        IOStream.cpp
        IOStream.h
        CachedStreamTree.cpp
        CachedStreamTree.h
        utilities.cpp
        utilities.h
        Tree.cpp
        Tree.h
        StreamTree.cpp
        StreamTree.h
)