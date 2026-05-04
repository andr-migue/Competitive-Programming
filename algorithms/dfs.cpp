#include <bits/stdc++.h>
#include "../structures/undirected_graph.hpp"

using namespace std;

// Recursive DFS to traverse a graph component.
// Used by `init` to visit every unreached node.
void dfs(structures::list_graph graph, vector<bool> visited, int node)
{
    visited[node] = true;

    for (int adj : graph[node]) 
    {
        if (!visited[adj])
        {
            dfs(graph, visited, adj);
        }
    }
}

// Starts DFS from every unvisited node.
// Used to traverse the whole graph by components.
void init(structures::list_graph graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) 
    {
        if (!visited[i])
        {
            dfs(graph, visited, i);
        }
    }
}