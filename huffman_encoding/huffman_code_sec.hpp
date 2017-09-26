//
// Created by vist on 17-9-26.
// version 1.0
//

#include <bits/stdc++.h>
using namespace std;
namespace Cpp {
// A Huffman tree node
    struct MinHeapNode {
        char data;
        unsigned freq;
        MinHeapNode *left, *right;

        MinHeapNode(char data, unsigned freq) {
            left = right = NULL;
            this->data = data;
            this->freq = freq;
        }
    };

    struct compare {
        bool operator()(MinHeapNode *l, MinHeapNode *r) {
            return (l->freq > r->freq);
        }
    };

    void printCodes(struct MinHeapNode *root, string str) {
        if (!root)
            return;
        if (root->data != '$')
            cout << root->data << ": " << str << "\n";
        printCodes(root->left, str + "0");
        printCodes(root->right, str + "1");
    }

// Huffman Tree
    void HuffmanCodes_Cpp(char data[], int freq[], int size) {
        struct MinHeapNode *left, *right, *top;

        priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
        for (int i = 0; i < size; ++i) {
            minHeap.push(new MinHeapNode(data[i], freq[i]));
        }

        while (minHeap.size() != 1) {
            left = minHeap.top();
            minHeap.pop();

            right = minHeap.top();
            minHeap.pop();

            top = new MinHeapNode('$', left->freq + right->freq);
            top->left = left;
            top->right = right;
            minHeap.push(top);
        }

        printCodes(minHeap.top(), "");
    }

}



