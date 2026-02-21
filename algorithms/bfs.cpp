#include <bits/stdc++.h>
#include "../structures/undirected_graph.hpp"

using namespace std;

vector<int> bfs(structures::list_graph &graph, int start)
{
    vector<int> dist(graph.n, INT_MAX);
    queue<int> nodes;
    
    dist[start] = 0;
    nodes.push(start);

    while (nodes.size() != 0)
    {
        int node = nodes.front();
        nodes.pop();

        for (int adj : graph.list[node]) 
        {
            if (dist[adj] != INT_MAX)
            {
                dist[adj] = dist[node] + 1;
                nodes.push(adj);
            }
        }
    }

    return dist;
}