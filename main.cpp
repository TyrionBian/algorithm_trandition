#include <iostream>

//#include "huffman_encoding/huffman_code.h"
//#include "huffman_encoding/huffman_code_sec.hpp"
#include "AVL_tree/avl_tree.c"
int main() {

    std::cout << "Hello, World!" << std::endl;
    // test huffman coding
/*    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffManCodes_C(arr, freq, size);
    using namespace Cpp;
    HuffmanCodes_Cpp(arr, freq, size);*/
    // test avl tree
    struct Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    printf("Preorder traversal of the constructed AVL"
                   " tree is \n");
    preOrder(root);
    return 0;
}