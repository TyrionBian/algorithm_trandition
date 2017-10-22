#include <iostream>

//#include "huffman_encoding/huffman_code.h"
//#include "huffman_encoding/huffman_code_sec.hpp"
//#include "AVL_tree/avl_tree.c"

//#define node splay_node
//#define rightRotate splay_node
//#include "splay_tree/splay_tree.c"
//#undef node

#include "shortest_path/dijkstra_pq.cpp"
int main() {

    using namespace dijkstra;
    std::cout << "Hello, World!" << std::endl;
    // test huffman coding
/*    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffManCodes_C(arr, freq, size);
    using namespace Cpp;
    HuffmanCodes_Cpp(arr, freq, size);*/
    // test avl tree
/*    struct Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    printf("Preorder traversal of the constructed AVL"
                   " tree is \n");
    preOrder(root);
    root = deleteNode(root, 10);
    printf("\nPreorder traversal after deletion of 10 \n");
    preOrder(root);*/
    // test splay tree
   /* struct splay_node *root = newNode(100);
    root->left = newNode(50);
    root->right = newNode(200);
    root->left->left = newNode(40);
    root->left->left->left = newNode(30);
    root->left->left->left->left = newNode(20);

    root = search(root, 20);
    printf("Preorder traversal of the modified Splay tree is \n");
    preOrder(root);*/
    // test for dijkstra
    int V = 9;
    dijkstra::Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);
    return 0;
}