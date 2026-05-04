#include <bits/stdc++.h>
#include <vector>
using namespace std;

namespace structures 
{
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
}
