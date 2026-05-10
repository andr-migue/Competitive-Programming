#include <bits/stdc++.h>
#include "../structures/all.hpp"

using namespace std;
using namespace structures;

// Dijkstra for minimum distances from start node.
// Works on a directed weighted graph with non-negative weights.
// Returns {distances, previous} where previous[v] is the predecessor of v
// on the shortest path from start (-1 if v is start or unreachable).
pair<vector<int>, vector<int>> dijkstra(directed_ponderaded_list_graph &graph, int start)
{
    int n = graph.size();
    vector<int> distances(n, INT_MAX);
    vector<int> previous(n, -1);

    distances[start] = 0;

    pair_min_heap heap; // {distance, node}
    heap.push({0, start});

    while (heap.size() != 0)
    {
        auto [dist, node] = heap.top();
        heap.pop();

        if (dist != distances[node])
        {
            continue;
        }

        for (auto [adj, weight] : graph[node])
        {
            if (distances[node] + weight < distances[adj])
            {
                distances[adj] = distances[node] + weight;
                previous[adj] = node;
                heap.push({distances[adj], adj});
            }
        }
    }

    return {distances, previous};
}