#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;

namespace structures 
{
    class directed_ponderaded_list_graph
    {
    public:
        int n;
        int edges;
        vector<vector<tuple<int, int>>> list;
    
        directed_ponderaded_list_graph(int nodes = 0)
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
    
    class directed_ponderaded_matrix_graph
    {
    public:
        int n;
        int edges;
        vector<vector<int>> matrix;
    
        directed_ponderaded_matrix_graph(int nodes = 0)
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
                if (matrix[u][v] == 0)
                {
                    edges++;
                }

                matrix[u][v] = w;
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