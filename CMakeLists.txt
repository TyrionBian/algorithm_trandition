cmake_minimum_required(VERSION 3.8)
project(algorithm_trandition)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp huffman_encoding/huffman_code_sec.hpp huffman_encoding/huffman_code.h AVL_tree/avl_tree.c Graph/adjList.cpp splay_tree/splay_tree.c shortest_path/dijkstra_pq.cpp RB_tree/RBTree.cpp)
add_executable(algorithm_trandition ${SOURCE_FILES})