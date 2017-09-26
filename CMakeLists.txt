cmake_minimum_required(VERSION 3.8)
project(algorithm_trandition)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp huffman_encoding/Solution.cpp huffman_encoding/Solution.hpp)
add_executable(algorithm_trandition ${SOURCE_FILES})