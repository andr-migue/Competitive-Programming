#include <bits/stdc++.h>
#include "../structures/undirected_graph.hpp"

using namespace std;

void bfs(structures::list_graph &graph, int start)
{
    vector<int> dist(graph.size(), INT_MAX);
    queue<int> nodes;
    
    dist[start] = 0;
    nodes.push(start);

    while (nodes.size() != 0)
    {
        int node = nodes.front();
        nodes.pop();

        for (int adj : graph[node]) 
        {
            if (dist[adj] != INT_MAX)
            {
                dist[adj] = dist[node] + 1;
                nodes.push(adj);
            }
        }
    }
}