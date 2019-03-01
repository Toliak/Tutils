cmake_minimum_required(VERSION 3.13)

project(BeautifulStream)

set(CMAKE_CXX_STANDARD 14)

add_executable(BeautifulStream src/main.cpp src/Stream.cpp src/Stream.h src/IOStream.cpp src/IOStream.h)