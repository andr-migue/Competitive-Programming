#include <bits/stdc++.h>
#include "../structures/all.hpp"

using namespace std;
using namespace structures;

ponderaded_list_graph prim(const ponderaded_list_graph& graph, int nodes)
{
    ponderaded_list_graph ans(nodes);
    vector<bool> mask(nodes, false);
    indexed_ponderaded_minheap heap;

    int count = 1;
    int node = 0;
    mask[node] = true;

    for (const auto& [adj, w] : graph.list[node])
    {
        heap.push({w, node, adj});
    }

    while (!heap.empty() && ans.edges < nodes - 1)
    {
        auto [w, u, v] = heap.top();
        heap.pop();

        if (mask[u] && mask[v])
        {
            continue;
        }

        int new_node = mask[u] ? v : u;

        if (mask[new_node])
        {
            continue;
        }

        ans.connect(u, v, w);
        mask[new_node] = true;
        count++;

        for (const auto& [adj, adj_w] : graph.list[new_node])
        {
            if (!mask[adj])
            {
                heap.push({adj_w, new_node, adj});
            }
        }

        if (count == nodes)
        {
            break;
        }
    }

    return ans;
}
