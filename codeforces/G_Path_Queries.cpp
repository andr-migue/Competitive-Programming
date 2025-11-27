#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mid(l, r) ((l + r) / 2)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) sort(v.rbegin(), v.rend())

class dsu
{
public:
    vector<int> parent, size;
    stack<tuple<int, int, int>> history;

    dsu(int n)
    {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int set_of(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = set_of(parent[x]);
        }
        return parent[x];
    }

    bool merge(int x, int y, int &paths)
    {
        x = set_of(x);
        y = set_of(y);

        if (x == y)
        {
            return false;
        }

        if (size[x] < size[y])
        {
            swap(x, y);
        }

        history.push({y, parent[y], size[x]});

        paths += 1LL * size[x] * size[y];

        parent[y] = x;
        size[x] += size[y];

        return true;
    }
};

signed main()
{
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges(n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
    }

    vector<pair<int, int>> queries(m);

    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        queries[i] = {q, i};
    }

    sort(edges);
    sort(queries);

    dsu dsu(n + 1);
    vector<int> ans(m);

    int paths = 0;
    int edge = 0;

    for (auto [q, i] : queries)
    {
        while (edge < edges.size() && edges[edge][0] <= q)
        {
            int u = edges[edge][1];
            int v = edges[edge][2];

            dsu.merge(u, v, paths);

            edge++;
        }

        ans[i] = paths;
    }

    for (int val : ans)
    {
        cout << val << " ";
    }
}