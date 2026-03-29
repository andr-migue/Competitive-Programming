#include <bits/stdc++.h>

using namespace std;

class dsu
{
public:
    vector<int> parent, size;
    int sets;

    dsu(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        sets = n;

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

        sets--;
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

    int GetSets()
    {
        return sets;
    }
};

class Solution
{
public:
    long long int numberOfPairs(vector<vector<int>> &pairs, int p, int n)
    {
        dsu dsu(n);

        for (int i = 0; i < p; i++)
        {
            int a = pairs[i][0], b = pairs[i][1];
            dsu.Merge(a, b);
        }

        vector<int> sizes(n);

        for (int i = 0; i < n; i++)
        {
            sizes[dsu.SetOf(i)]++;
        }

        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (sizes[i] > 0)
            {
                long long size = sizes[i];
                sum += size * (size - 1) / 2;
            }
        }

        long long ans = (n * (n - 1) / 2) - sum;
        
        return ans;
    }
};