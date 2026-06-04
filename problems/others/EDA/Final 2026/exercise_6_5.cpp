#include <bits/stdc++.h>
#include "../../../../algorithms/ford_fulkerson.cpp"

using namespace std;
using namespace structures;

bool solve(vector<int> &out_deg, vector<int> &in_deg, int n)
{
    int total_out = 0;
    int total_in = 0;

    for (int i = 0; i < n; i++)
    {
        total_out += out_deg[i];
        total_in  += in_deg[i];

        if (out_deg[i] > n - 1 || in_deg[i] > n - 1) 
        {
            return false;
        }
    }

    if (total_out != total_in)
    {
        return false;
    } 

    int S = 0; 
    int T = 2 * n + 1;

    directed_ponderaded_list_graph graph(2 * n + 2);

    for (int i = 0; i < n; i++)
    {
        graph.connect(S, i + 1, out_deg[i]);     
        graph.connect(n + i + 1, T, in_deg[i]);     

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                graph.connect(i + 1, n + j + 1, 1); 
            }
        }
    }

    return ford_fulkerson(graph, S, T) == total_out;
}