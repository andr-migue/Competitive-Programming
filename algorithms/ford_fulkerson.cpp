#include <bits/stdc++.h>
#include "../structures/all.hpp"

using namespace std;
using namespace structures;

// DFS over the residual graph; returns the bottleneck of the path found, -1 if none
int dfs(int node, int t, int flow, vector<unordered_map<int, int>> &res, vector<bool> &visited)
{
    if (node == t) return flow;

    visited[node] = true;

    for (auto &[adj, capacity] : res[node])
    {
        if (!visited[adj] && capacity > 0)
        {
            int bottleneck = dfs(adj, t, min(flow, capacity), res, visited);

            if (bottleneck != -1)
            {
                res[node][adj] -= bottleneck;
                res[adj][node] += bottleneck;

                return bottleneck;
            }
        }
    }

    return -1;
}

// Ford-Fulkerson for maximum flow from s to t.
// Edge weights in the graph represent capacities.
// Returns the total maximum flow.
int ford_fulkerson(directed_ponderaded_list_graph &graph, int s, int t)
{
    int n = graph.size();
    vector<unordered_map<int, int>> res(n);

    for (int node = 0; node < n; node++)
    {
        for (auto [adj, capacity] : graph[node])
        {
            res[node][adj] += capacity;
        }
    }

    int flow = 0;
    int bottleneck = 0;

    while (bottleneck != -1)
    {
        vector<bool> visited(n, false);

        bottleneck = dfs(s, t, INT_MAX, res, visited);

        if (bottleneck != -1)
        {
           flow += bottleneck; 
        }  
    }

    return flow;
}
