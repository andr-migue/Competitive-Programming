#include <bits/stdc++.h>
#include "../../../../algorithms/dijkstra.cpp"

using namespace std;

int solve(directed_ponderaded_list_graph &graph, int n)
{
    pair_min_heap heap;

    for (int i = 0; i < n; i++)
    {
        auto [distances, previous, max_distance] = dijkstra(graph, i);
        heap.push({max_distance, i});
    }

    auto [max_distance, node] = heap.top();

    return node;
}