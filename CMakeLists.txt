cmake_minimum_required(VERSION 3.8)
project(algorithm_trandition)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp huffman_encoding/huffman_code_sec.hpp huffman_encoding/huffman_code.h)
add_executable(algorithm_trandition ${SOURCE_FILES})