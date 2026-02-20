#include <bits/stdc++.h>
using namespace std;

class list_graph
{
public:
    int n;
    vector<vector<int>> list;

    list_graph(int nodes = 0)
    {
        n = nodes;
        list.resize(nodes);
    }

    void add()
    {
        list.push_back(vector<int>());
        n++;
    }

    void connect(int u, int v)
    {
        if (u < n && v < n)
        {
            list[u].push_back(v);
            list[v].push_back(u);
        }
    }

    int size()
    {
        return n;
    }
};

class matrix_graph
{
public:
    int n;
    vector<vector<int>> matrix;

    matrix_graph(int nodes)
    {
        n = nodes;
        matrix.resize(n, vector<int>(n, 0));
    }

    void connect(int u, int v)
    {
        if (u < n && v < n)
        {
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
    }

    int size()
    {
        return n;
    }
};