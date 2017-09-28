//
// Created by vist on 17-9-28.
//
// Adjacency list for undirected graph.
#include <stdio.h>
#include <stdlib.h>
struct AdjListNode{
    int dest;
    struct AdjListNode* next;
};

struct AdjList{
    struct AdjListNode *head;
};

struct Graph{
    int V;
    struct  AdjList * array;
};

struct AdjListNode * newAdjListNode(int dest){
    struct AdjListNode * newNode = (struct AdjListNode *) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V){
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph-> V = V;
    graph->array = (struct AdjList*) malloc(sizeof(struct AdjList));

    int i;
    for(i=0; i<V; ++i){
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest){
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}
