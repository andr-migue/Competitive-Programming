#include <bits/stdc++.h>
#include "../../structures/undirected_graph.hpp"

using namespace std;

bool is_bipartite(structures::list_graph &graph)
{
    int n = graph.n;
    vector<int> colors(n, 0);

    for (int u = 0; u < n; u++) 
    {
        if (colors[u] != 0)
        {
            continue;
        }

        colors[u] = 1;
        queue<int> nodes;
        nodes.push(u);

        while (nodes.size() != 0) 
        {
            int node = nodes.front();
            nodes.pop();

            for (int adj : graph.list[node]) 
            {
                if (colors[adj] == 0)
                {
                    colors[adj] = colors[node] == 1 ? 2 : 1;
                    nodes.push(adj);
                }
                else if (colors[adj] == colors[node])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

signed main()
{
    structures::list_graph g1(4);
    g1.connect(0, 1);
    g1.connect(1, 2);
    g1.connect(2, 3);

    cout << (is_bipartite(g1) ? "YES" : "NO") << "\n";

    structures::list_graph g2(3);
    g2.connect(0, 1);
    g2.connect(1, 2);
    g2.connect(2, 0);

    cout << (is_bipartite(g2) ? "YES" : "NO") << "\n"; 
}