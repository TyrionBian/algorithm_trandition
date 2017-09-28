#include <iostream>

//#include "huffman_encoding/huffman_code.h"
//#include "huffman_encoding/huffman_code_sec.hpp"
//#include "AVL_tree/avl_tree.c"
#define node splay_node
#define rightRotate splay_node
#include "splay_tree/splay_tree.c"
#undef node
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
    struct splay_node *root = newNode(100);
    root->left = newNode(50);
    root->right = newNode(200);
    root->left->left = newNode(40);
    root->left->left->left = newNode(30);
    root->left->left->left->left = newNode(20);

    root = search(root, 20);
    printf("Preorder traversal of the modified Splay tree is \n");
    preOrder(root);
    return 0;
}