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

    int SetOf(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = SetOf(parent[x]);
        }
        return parent[x];
    }

    bool Merge(int x, int y)
    {
        x = SetOf(x);
        y = SetOf(y);

        if (x == y)
        {
            return false;
        }

        if (size[x] > size[y])
        {
            parent[y] = x;
            size[x] += size[y];
        }
        else
        {
            parent[x] = y;
            size[y] += size[x];
        }

        return true;
    }

    bool Same(int x, int y)
    {
        return SetOf(x) == SetOf(y);
    }

    int GetSize(int x)
    {
        return size[SetOf(x)];
    }
};