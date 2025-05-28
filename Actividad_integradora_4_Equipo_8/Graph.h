#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "LinkedList.h"

static const int INF = 0x3f3f3f3f;

// Grafo genérico: addNode O(1), addEdge O(1), getDegree O(1)
// Dijkstra O(n^2 + m)
template <class T>
class Graph {
private:
    int numNodes;
    int numEdges;
    bool directed;
    bool weighted;
    std::map<int, T> info;
    std::vector<LinkedList<std::pair<int,int>>> adj;

public:
    Graph(bool dir = true, bool wt = true)
        : numNodes(0), numEdges(0), directed(dir), weighted(wt) {}

    int addNode(const T& data) {
        int idx = numNodes;
        info[idx] = data;
        adj.emplace_back();
        numNodes += 1;
        return idx;
    }

    void addEdge(int u, int v, int w = 1) {
        adj[u].addLast({v, w});             // O(1)
        if (!directed) {
            adj[v].addLast({u, w});         // O(1)
        }
        numEdges += 1;
    }

    int getDegree(int u) const {
        return adj[u].getNumElements();    // O(1)
    }

    std::pair<std::vector<int>, std::vector<int>> dijkstra(int src) {
        std::vector<int> dist(numNodes, INF);
        std::vector<int> prev(numNodes, -1);
        std::vector<bool> used(numNodes, false);

        dist[src] = 0;
        for (int it = 0; it < numNodes; ++it) {  // O(n)
            int u = -1;
            for (int i = 0; i < numNodes; ++i) { // O(n)
                if (!used[i] && (u < 0 || dist[i] < dist[u])) {
                    u = i;
                }
            }
            if (u < 0 || dist[u] == INF) {
                break;
            }
            used[u] = true;

            auto* p = adj[u].getHead();         // iterar aristas de u: O(deg(u))
            while (p) {
                int v = p->data.first;
                int w = p->data.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    prev[v] = u;
                }
                p = p->next;
            }
        }
        return {dist, prev};                    
    }
};

#endif