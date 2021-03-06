//
// Created by vist on 17-9-27.
//
#include <stdio.h>
#include <stdlib.h>


// AAVL tree node
struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b);

int height(struct Node *N){
    if(N==NULL)
        return 0;
    return N->height;
}

int max(int a, int b){
    return (a>b)?a:b;
}

struct Node* newNode(int key){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}

// right rotate subtree rooted with  y
struct Node *rightRotate(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    //Perform rotation
    x->right = y;
    y->left = T2;

    // update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}

// left rotate subtree rooted with x
struct Node *leftRotate(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
}

//get balance
int getBalance(struct Node *N){
    if (N==NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int key){
    //1. perform the normal BST insertion
    if (node==NULL)
        return(newNode(key));
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    //2. update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    //3. get the balance factor ot this ancestor node
    int balance = getBalance(node);

    // if the node becomes unbalanced, then there are 4 cases
    // left left case
    if (balance>1 && key< node->left->key)
        return rightRotate(node);
    // right right case
    if (balance>1 && key > node->right->key)
        return leftRotate(node);
    // left right case
    if (balance>1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // right left case
    if (balance>1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct Node* minValueNode(struct Node* node){
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key){
    //1. preform standard BST delete
    if (root==NULL)
        return root;

    if(key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
        root->right = deleteNode(root->right, key);
    else{
        if((root->left == NULL) || (root->right == NULL)){
            struct Node *temp = root->left? root->left:root->right;

            if(temp == NULL){
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            struct Node *temp = minValueNode(root->right);
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if(root == NULL)
        return root;

    //2.
    root->height = 1 + max(height(root->left), height(root->right));
    //3.
    int balance = getBalance(root);

    // left left case
    if (balance>1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    // left right case
    if (balance>1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // right right case
    if (balance>1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    // right left case
    if (balance>1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void preOrder(struct Node *root){
    if (root != NULL){
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
