#include <bits/stdc++.h>
#include <stack>
#include "../structures/all.hpp"

using namespace std;

void dfs_build(structures::directed_list_graph &graph, vector<bool> &visited, int node, stack<int> &S)
{
    visited[node] = true;

    for (int adj : graph[node]) 
    {
        if (!visited[adj])
        {
            dfs_build(graph, visited, adj, S);
        }
    }

    S.push(node);
}

stack<int> build_stack(structures::directed_list_graph &graph, int n)
{
    vector<bool> visited(n, false);
    stack<int> S;

    for (int i = 0; i < n; i++) 
    {
        if (!visited[i])
        {
            dfs_build(graph, visited, i, S);
        }
    }

    return S;
}

void dfs_assign(structures::directed_list_graph &T_graph, vector<int> &comp, int node, int id)
{
    comp[node] = id;

    for (int adj : T_graph[node])
    {
        if (comp[adj] == -1)
        {
            dfs_assign(T_graph, comp, adj, id);
        }
    }
}

vector<int> assign(structures::directed_list_graph &T_graph, int n, stack<int> S)
{
    int id = 0;
    vector<int> comp(n, -1);

    while (S.size() != 0)
    {
        int v = S.top();
        S.pop();

        if (comp[v] == -1)
        {
            dfs_assign(T_graph, comp, v, id);
            id++;
        }
    }

    return comp;
}



structures::directed_list_graph build_t_graph(const structures::directed_list_graph &graph, int n)
{
    structures::directed_list_graph T_graph(n);

    for (int u = 0; u < n; ++u)
    {
        for (int adj : graph[u])
        {
            T_graph.connect(adj, u);
        }
    }

    return T_graph;
}

// Kosaraju: two DFS to compute strongly connected components.
// Returns a vector `comp` of size n where comp[v] is component id (0..k).
vector<int> kosaraju(structures::directed_list_graph &graph)
{
    int n = graph.size();
    stack S = build_stack(graph, n);
    auto T_graph = build_t_graph(graph, n);
    auto comp = assign(T_graph, n, S);

    return comp;
}