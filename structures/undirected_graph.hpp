#include <bits/stdc++.h>
#include <vector>
using namespace std;

namespace structures 
{
    // Undirected graph stored as adjacency lists.
    // Provides O(1) access to neighbors through `operator[]`.
    class list_graph
    {
    public:
        int n;
        int edges;
        vector<vector<int>> list;
    
        list_graph(int nodes = 0)
        {
            n = nodes;
            edges = 0;
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
                edges++;
            }
        }

        vector<int>& operator[](int index)
        {
            return list[index];
        }

        const vector<int>& operator[](int index) const
        {
            return list[index];
        }

        int size()
        {
            return n;
        }
    };
    
    // Undirected graph stored as an adjacency matrix.
    // Uses 1 to mark the presence of an edge.
    class matrix_graph
    {
    public:
        int n;
        int edges;
        vector<vector<int>> matrix;
    
        matrix_graph(int nodes)
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
    
        void connect(int u, int v)
        {
            if (u < n && v < n)
            {
                matrix[u][v] = 1;
                matrix[v][u] = 1;
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