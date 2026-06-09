#include <bits/stdc++.h>
#include "../../../../algorithms/floyd_warshall.cpp"

using namespace std;
using namespace structures;

int solve(directed_ponderaded_matrix_graph &graph, int n)
{
    vector<vector<int>> dist = floyd_warshall(graph);

    int best_node = 0;
    int best_ecc  = INT_MAX;

    for (int v = 0; v < n; v++)
    {
        int ecc = *max_element(dist[v].begin(), dist[v].end());

        if (ecc < best_ecc)
        {
            best_ecc  = ecc;
            best_node = v;
        }
    }

    return best_node;
}
