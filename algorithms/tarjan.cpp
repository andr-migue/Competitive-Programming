#include <bits/stdc++.h>
#include "../structures/undirected_graph.hpp"

using namespace std;
using namespace structures;

// DFS helper: fills disc[] and low[] to detect bridges via back-edge analysis.
void dfs_tarjan(list_graph &graph, vector<int> &disc, vector<int> &low,
                vector<pair<int, int>> &bridges, int v, int parent, int &timer)
{
    disc[v] = low[v] = timer++;

    for (int adj : graph[v])
    {
        if (disc[adj] == -1)
        {
            dfs_tarjan(graph, disc, low, bridges, adj, v, timer);
            low[v] = min(low[v], low[adj]);

            if (low[adj] > disc[v])
            {
                bridges.push_back({v, adj});
            }
        }
        else if (adj != parent)
        {
            low[v] = min(low[v], disc[adj]);
        }
    }
}

// Tarjan's bridge-finding algorithm on an undirected graph.
// Returns all bridge edges as pairs {u, v} where u < v is not guaranteed.
// A bridge is an edge whose removal disconnects the graph.
// Time complexity: O(|V| + |E|).
vector<pair<int, int>> tarjan(list_graph &graph)
{
    int n = graph.size();
    vector<int> disc(n, -1);
    vector<int> low(n, 0);
    vector<pair<int, int>> bridges;
    int timer = 0;

    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
        {
            dfs_tarjan(graph, disc, low, bridges, i, -1, timer);
        }
    }

    return bridges;
}
