//
// Created by vist on 17-9-29.
//
#include <stdlib.h>
#include <stdio.h>
// An AVL tree node

struct node{
    int key;
    struct node *left, *right;
};

struct node* newNode(int key){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}


struct node *rightRotate(struct node *x){
    struct node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
};

struct node *leftRotate(struct node *x){
    struct node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}


struct node *splay(struct node *root, int key){
    if(root==NULL || root->key == key)
        return root;
    if (root->key > key){
        if(root->left == NULL) return root;
        if (root->left->key > key){
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } else if (root->left->key < key){
            root->left->right = splay(root->left->right, key);
            if(root->left->right != NULL){
                root->left = leftRotate(root->left);
            }
        }
        return (root->left == NULL)? root:rightRotate(root);
    } else {
        if (root->right == NULL) return root;
        if (root->right->key > key){
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        } else if (root->right->key < key){
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        return (root->right == NULL)? root:leftRotate(root);
    }
}

struct node *search(struct node *root, int key){
    return splay(root, key);
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
};
