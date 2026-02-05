#include <bits/stdc++.h>
using namespace std;

class dsu
{
public:
    vector<int> parent, size;

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

        parent[y] = x;
        size[x] += size[y];

        return true;
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
