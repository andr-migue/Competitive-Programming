#include <bits/stdc++.h>
using namespace std;

class dsu
{
public:
    vector<int> parent, size;
    stack<tuple<int, int, int>> history; // y, parent[y], size[x]

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
            return set_of(parent[x]);
        }
        return x;
    }

    bool merge(int x, int y)
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

        parent[y] = x;
        size[x] += size[y];

        return true;
    }

    void undo()
    {
        if (history.size() == 0)
        {
            return;
        }

        auto [y, parent_y, size_x] = history.top();
        history.pop();

        int x = parent[y];
        parent[y] = parent_y;
        size[x] = size_x;
    }

    int checkpoint()
    {
        return history.size();
    }

    void rollback(int checkpoint)
    {
        while ((int)history.size() > checkpoint)
        {
            undo();
        }
    }

    bool same(int x, int y)
    {
        return set_of(x) == set_of(y);
    }

    int get_size(int x)
    {
        return size[set_of(x)];
    }
};
