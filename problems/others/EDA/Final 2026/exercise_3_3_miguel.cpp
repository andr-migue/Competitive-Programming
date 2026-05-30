#include <bits/stdc++.h>
#include "../../../../algorithms/kruskal.cpp"
#include "../../../../structures/heap.hpp"

using namespace std;

int solve(vector<Edge> &graph, int n, int k)
{
    ponderaded_list_graph tree = kruskal(graph, n);

    int ans = 0;
    maxHeap heap;

    for (int u = 0; u < n; u++)
    {
        for (auto [v, w] : tree.list[u])
        {
            if (u < v)
            {
                heap.push(w);        
            }
        }
    }

    while (!heap.empty())
    {
        if (k - 1 > 0)
        {
            heap.pop();
        }
        else 
        {
            ans += heap.top();
            heap.pop();
        }

        k--;
    }

    return ans;
}