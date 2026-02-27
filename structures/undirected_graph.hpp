#include <bits/stdc++.h>
#include <vector>
using namespace std;

namespace structures 
{
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