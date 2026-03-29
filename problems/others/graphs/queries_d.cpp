#include <bits/stdc++.h>

using namespace std;

class graph
{
public:
    int n;
    vector<vector<int>> list;

    graph(int nodes = 0)
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

vector<int> solve(vector<pair<int, int>> &points, int d, vector<pair<int, int>> queries)
{
    int n = points.size();
    vector<int> ans;
    
    graph graph(n);

    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++)
        {
            auto [x1, y1] = points[i];
            auto [x2, y2] = points[j];

            double dist = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

            if (dist <= d)
            {
                graph.connect(i, j);
            }
        }
    }

    map<pair<int, int>, int> lin; // point, node

    for (int i = 0; i < n; i++)
    {
        lin[points[i]] = i;
    }

    for (int q = 0; q < queries.size(); q++)
    {
        ans.push_back(graph.list[lin[queries[q]]].size());
    }

    return ans;
}

signed main()
{
    vector<pair<int, int>> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}};
    vector<pair<int, int>> queries = {{0, 0}, {1, 1}, {2, 2}};
    int d = 2;

    vector<int> ans = solve(points, d, queries);

    for (int value : ans)
    {
        cout << value << endl;
    }
}