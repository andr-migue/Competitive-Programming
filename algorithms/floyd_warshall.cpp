#include <bits/stdc++.h>
#include "../structures/directed_ponderaded_graph.hpp"

using namespace std;
using namespace structures;

// Floyd-Warshall all-pairs shortest paths on a directed weighted graph.
// Requires a matrix representation; INT_MAX marks unreachable pairs.
// Time complexity: O(|V|^3).
vector<vector<int>> floyd_warshall(directed_ponderaded_matrix_graph &graph)
{
    int n = graph.size();
    const int INF = INT_MAX / 2;

    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int u = 0; u < n; u++)
    {
        dist[u][u] = 0;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0)
            {
                dist[u][v] = graph[u][v];
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (dist[u][k] < INF && dist[k][v] < INF)
                {
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }
    }

    return dist;
}
