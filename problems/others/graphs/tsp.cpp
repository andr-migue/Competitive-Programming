#include <bits/stdc++.h>
#include <climits>
#include "../../structures/undirected_graph.hpp"

using namespace std;
using namespace structures;

int tsp(list_graph graph, vector<pair<int, int>> railways) 
{
    int n = graph.size();
    deque<int> dq;
    vector<int> dist(n, INT_MAX);

    dist[0] = 0;
    dq.push_back(0);

    while (dq.size() != 0)
    {
        int node = dq.front();
        dq.pop_front();

        for (int adj : graph[node]) 
        {
            if (dist[node] + 1 < dist[adj])
            {
                dist[adj] = dist[node] + 1;
                dq.push_back(adj);
            }
        }

        for (auto [a, b] : railways) 
        {
            if (node == a && dist[node] < dist[b])
            {
                dist[b] = dist[node];
                dq.push_front(b);
            }
            else if (node == b && dist[node] < dist[a])
            {
                dist[a] = dist[node];
                dq.push_front(a);
            }
        }
    }

    return dist[n - 1];
}