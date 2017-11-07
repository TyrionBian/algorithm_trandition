//
// Created by vist on 17-10-23.
//

#include <bits/stdc++.h>
using namespace std;

enum Color {RED, BLACK};

struct Node
{
    int data;
    bool color;
    Node *left, *right, * parent;

    // Constructor
    Node (int data) {
        this->data = data;
        left = right = parent = NULL;
    }
};

class RBTree{
private:
    Node *root;

protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);

public:
    //Constructor
    RBTree() {root = NULL;}
    void insert(const int &n);
    void inorder();
    void levelOrder();
};


// A recursive function to do level order traversal
void inorderHelper(Node *root)
{
    if (root == NULL)
        return;
    inorderHelper(root->left);
    cout << root->data << "   ";
    inorderHelper(root->right);
}

/*
 * A utility function to insert a new node with given key in BST
 */
Node * BSTInsert(Node* root, Node *pt)
{
    //if the tree is empty, return a new node
    if (root == NULL)
        return pt;

    if (pt->data < root->data){
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    } else if (pt->data > root->data) {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }
    return root;
}

// Utility function to do level order traversal
void levelOrderHelper(Node *root)
{
    if (root == NULL)
        return;
    std::queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

void RBTree::rotateLeft(Node *&root, Node *&pt) {
    Node *pt_right = pt->right;

}





























