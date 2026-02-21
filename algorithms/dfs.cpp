#include <bits/stdc++.h>
#include "../structures/undirected_graph.hpp"

using namespace std;

void dfs(structures::list_graph graph, vector<bool> visited, int node)
{
    visited[node] = true;

    for (int adj : graph.list[node]) 
    {
        if (!visited[adj])
        {
            dfs(graph, visited, adj);
        }
    }
}

void init(structures::list_graph graph)
{
    int n = graph.n;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) 
    {
        if (!visited[i])
        {
            dfs(graph, visited, i);
        }
    }
}