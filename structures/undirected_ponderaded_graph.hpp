#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;

namespace structures 
{
    // Undirected weighted graph stored as adjacency lists.
    // Each edge stores the destination and its weight.
    class ponderaded_list_graph
    {
    public:
        int n;
        int edges;
        vector<vector<tuple<int, int>>> list;
    
        ponderaded_list_graph(int nodes = 0)
        {
            n = nodes;
            edges = 0;
            list.resize(nodes);
        }
    
        void add()
        {
            list.push_back(vector<tuple<int, int>>());
            n++;
        }
    
        void connect(int u, int v, int w)
        {
            if (u < n && v < n)
            {
                list[u].push_back({v, w});
                list[v].push_back({u, w});
                edges++;
            }
        }

        vector<tuple<int, int>>& operator[](int index)
        {
            return list[index];
        }

        const vector<tuple<int, int>>& operator[](int index) const
        {
            return list[index];
        }

        int size()
        {
            return n;
        }
    };
    
    // Undirected weighted graph stored as an adjacency matrix.
    // The matrix stores the edge weight between both endpoints.
    class ponderaded_matrix_graph
    {
    public:
        int n;
        int edges;
        vector<vector<int>> matrix;
    
        ponderaded_matrix_graph(int nodes)
        {
            n = nodes;
            edges = 0;
            matrix.resize(n, vector<int>(n, 0));
        }

        void add()
        {
            for (auto &row : matrix)
            {
                row.push_back(0);
            }

            n++;
            matrix.push_back(vector<int>(n, 0));
        }
    
        void connect(int u, int v, int w)
        {
            if (u < n && v < n)
            {
                matrix[u][v] = w;
                matrix[v][u] = w;
                edges++;
            }
        }

        vector<int>& operator[](int index)
        {
            return matrix[index];
        }

        const vector<int>& operator[](int index) const
        {
            return matrix[index];
        }

        int size()
        {
            return n;
        }
    };
}