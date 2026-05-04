#include <bits/stdc++.h>
#include <vector>
using namespace std;

namespace structures 
{
    // Directed graph stored as adjacency lists.
    // Useful for traversals and graph algorithms on sparse graphs.
    class directed_list_graph
    {
    public:
        int n;
        int edges;
        vector<vector<int>> list;
    
        directed_list_graph(int nodes = 0)
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

    // Directed graph stored as an adjacency matrix.
    // Uses 1 to mark a directed edge from `u` to `v`.
    class directed_matrix_graph
    {
    public:
        int n;
        int edges;
        vector<vector<int>> matrix;

        directed_matrix_graph(int nodes = 0)
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
                if (matrix[u][v] == 0)
                {
                    edges++;
                    matrix[u][v] = 1;
                }
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
