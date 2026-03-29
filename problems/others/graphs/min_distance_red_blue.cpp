#include <bits/stdc++.h>

using namespace std;

class graph
{
public:
    int n;
    vector<tuple<vector<int>, char>> list;

    graph(int nodes = 0)
    {
        n = nodes;
        list.resize(nodes);
    }

    void add(char color)
    {
        list.push_back({vector<int>(), color});
        n++;
    }

    void connect(int u, int v)
    {
        if (u < n && v < n)
        {
            get<0>(list[u]).push_back(v);
            get<0>(list[v]).push_back(u);
        }
    }

    int size()
    {
        return n;
    }
};

int solve(graph &graph)
{
    int size = graph.size();

    int red = size;
    int blue = size + 1;

    graph.add('r');

    for (int i = 0; i < size; i++)
    {
        if (i != red)
        {
            auto [adj, color] = graph.list[i];
    
            if (color == 'r')
            {
                graph.connect(red, i);
            }
        }
    }

    graph.add('b');

    for (int i = 0; i < size; i++)
    {
        if (i != blue)
        {
            auto [adj, color] = graph.list[i];
    
            if (color == 'b')
            {
                graph.connect(blue, i);
            }
        }
    }

    vector<bool> mask(size + 2, false);
    queue<pair<int, int>> queue;
    
    queue.push({red, 0});
    mask[red] = true;

    while (!queue.empty()) 
    {
        auto [node, dist] = queue.front();
        queue.pop();

        auto [adj, color] = graph.list[node];

        for (int v : adj)
        {
            if (v == blue)
            {
                return dist - 1;
            }

            if (!mask[v])
            {
                mask[v] = true;
                queue.push({v, dist + 1});
            }
        }
    }

    return -1;
}

signed main()
{
    graph graph;
    graph.add('r');  
    graph.add('y');  
    graph.add('g');
    graph.add('p');  
    graph.add('b');  
    graph.connect(0, 1);
    graph.connect(1, 2);
    graph.connect(2, 3);
    graph.connect(3, 4);

    cout << solve(graph) << endl;
}