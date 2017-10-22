//
// Created by vist on 17-10-22.
//

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
namespace dijkstra
{
    // Integer Pair
    typedef pair<int, int> iPair;

// This class represents a directed graph using adjacency list representation
    class Graph
    {
        int V;  //No. of vertices
        list< pair<int, int >> *adj;

    public:
        Graph(int V);   //Constructor

        // function to add an edge to graph
        void addEdge(int u, int v, int w);

        // prints shortest path from s
        void shortestPath(int s);
    };

    Graph::Graph(int V) {
        this->V = V;
        adj = new list<iPair> [V];
    }

    void Graph::addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }


// Prints shortest paths from src to all other vertices
    void Graph::shortestPath(int src) {
        /*
         * Create a priority queue to store vertices that
         * are being preprocessed. This is weird syntax in c++.
         */
        priority_queue<iPair, vector <iPair>, greater<iPair>> pq;

        // Create a vector for distances and initialize all distances as infinite
        vector<int> dist(V, INF);

        // Insert source itself in priority queue and initialize tis distance as 0.
        pq.push(make_pair(0, src));
        dist[src] = 0;

        /*
         * Looping till priority queue becomes empty
         */
        while (!pq.empty())
        {
            /*
             * The first vertex in pair is the minimum distance vertex,
             * extract it from priority queue.
             * vertex label is stored in second of pairs
             */
            int u = pq.top().second;
            pq.pop();

            // i if used to get all adjacent vertices of a vertex
            list< pair<int, int>>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                // Get vertex label and weight of current adjacent of u
                int v = (*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }

        }

        for (int i=0; i <V; ++i)
            printf("%d \t\t %d\n", i, dist[i]);
    }
}



