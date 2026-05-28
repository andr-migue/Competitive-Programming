#include <bits/stdc++.h>
#include "../../../../structures/undirected_graph.hpp"
#include "../../../../algorithms/tarjan.cpp"

using namespace std;
using namespace structures;

void dfs_comp(list_graph &graph, unordered_set<int> &bridge_set,
              vector<int> &comp, int v, int c, int n)
{
    comp[v] = c;

    for (int adj : graph[v])
    {
        if (comp[adj] == -1)
        {
            int key = min(v, adj) * n + max(v, adj);

            if (!bridge_set.count(key))
            {
                dfs_comp(graph, bridge_set, comp, adj, c, n);
            }
        }
    }
}

class bridge_tree
{
private:
    int n;
    vector<int> components;
    int comps_count = 0;
    list_graph tree;  
    vector<int> depth; 
    vector<int> parent; 

    void bfs_assign_depth_par(int root)
    {
        vector<bool> visited(comps_count, false);
        queue<int> q;

        visited[root] = true;
        q.push(root);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();

            for (int adj : tree[v])
            {
                if (!visited[adj])
                {
                    visited[adj] = true;
                    depth[adj] = depth[v] + 1;
                    parent[adj] = v;
                    q.push(adj);
                }
            }
        }
    }

    int lca(int a, int b)
    {
        while (depth[a] > depth[b]) 
            a = parent[a];

        while (depth[b] > depth[a]) 
            b = parent[b];

        while (a != b) 
        { 
            a = parent[a]; 
            b = parent[b]; 
        }

        return a;
    }

public:
    bridge_tree(list_graph &graph)
    {
        n = graph.size();
        auto [bridge_set, bridges] = tarjan_set(graph);
        components.assign(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (components[i] == -1)
            {
                dfs_comp(graph, bridge_set, components, i, comps_count++, n);
            }
        }

        tree = list_graph(comps_count);

        for (auto [u, v] : bridges)
        {
            tree.connect(components[u], components[v]);
        }

        depth.assign(comps_count, 0);
        parent.assign(comps_count, -1);

        bfs_assign_depth_par(0);
    }

    int count_bridges(int a, int b)
    {
        int ca = components[a];
        int cb = components[b];
        int l  = lca(ca, cb);

        return depth[ca] + depth[cb] - 2 * depth[l];
    }
};

int main()
{
    list_graph g(6);
    g.connect(0, 1);
    g.connect(1, 2);
    g.connect(2, 3);
    g.connect(3, 4);
    g.connect(4, 2);
    g.connect(4, 5);

    bridge_tree bt(g);

    cout << "CantPuentes(0, 5) = " << bt.count_bridges(0, 5) << "\n";
    cout << "CantPuentes(3, 4) = " << bt.count_bridges(3, 4) << "\n";
    cout << "CantPuentes(0, 4) = " << bt.count_bridges(0, 4) << "\n";

    return 0;
}