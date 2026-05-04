#include <bits/stdc++.h>
#include "../structures/all.hpp"

using namespace std;

vector<int> dijkstra(structures::directed_ponderaded_list_graph &graph)
{
    int n = graph.size();
    vector<int> distances(n, INT_MAX);
    
    distances[0] = 0;

    structures::pair_min_heap heap; // {distance, node}
    heap.push({0, 0});

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
                heap.push({distances[adj], adj});
            }
        }
    }

    return distances;
}