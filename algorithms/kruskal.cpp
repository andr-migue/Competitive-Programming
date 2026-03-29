#include <bits/stdc++.h>
#include "../structures/all.hpp"

using namespace std;
using namespace structures;

struct Edge
{
    int u, v, w;
};

ponderaded_list_graph kruskal(vector<Edge> graph, int nodes)
{
    ponderaded_list_graph ans(nodes);
    dsu dsu(nodes);

    sort(graph.begin(), graph.end(), [](const auto &a, const auto &b){return a.w < b.w;});

    for (const auto& edge : graph)
    {
        auto [u, v, w] = edge;

        if (dsu.merge(u, v))
        {
            ans.connect(u, v, w);

            if (ans.edges == nodes - 1)
            {
                break;
            }
        }
    }

    return ans;
}