#include <bits/stdc++.h>
#include "../structures/all.hpp"

using namespace std;
using namespace structures;

void dfs_topological_sort(directed_ponderaded_list_graph &graph, vector<bool> &visited, vector<int> &order, int node)
{
     visited[node] = true;

    for (auto [adj, weight] : graph[node])
    {
        if (!visited[adj])
        {
            dfs_topological_sort(graph, visited, order, adj);
        }
    }
    
    order.push_back(node);
}

// Computes topological order of a DAG via post-order DFS.
// Returns nodes ordered so that for every edge u→v, u appears before v.
vector<int> topological_sort(directed_ponderaded_list_graph &graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> order;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs_topological_sort(graph, visited, order, i);
        }
    }

    reverse(order.begin(), order.end());
    return order;
}

// DAG shortest path from start using topological order.
// Supports negative weights. Works only on directed acyclic graphs.
// Returns {distances, previous} where previous[v] is the predecessor of v
// on the shortest path from start (-1 if v is start or unreachable).
pair<vector<int>, vector<int>> dag_shortest_path(directed_ponderaded_list_graph &graph, int start)
{
    int n = graph.size();
    vector<int> distances(n, INT_MAX);
    vector<int> previous(n, -1);

    distances[start] = 0;

    vector<int> order = topological_sort(graph);

    for (int node : order)
    {
        if (distances[node] == INT_MAX)
        {
            continue;
        }

        for (auto [adj, weight] : graph[node])
        {
            if (distances[node] + weight < distances[adj])
            {
                distances[adj] = distances[node] + weight;
                previous[adj] = node;
            }
        }
    }

    return {distances, previous};
}