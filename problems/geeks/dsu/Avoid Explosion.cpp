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
};

class Solution
{
public:
    vector<string> avoidExplosion(vector<vector<int>> mix, int n, vector<vector<int>> danger, int m)
    {
        vector<string> ans(n);
        int maxVal = 1;

        for (int i = 0; i < n; i++)
        {
            maxVal = max(maxVal, max(mix[i][0], mix[i][1]));
        }

        for (int i = 0; i < m; i++)
        {
            maxVal = max(maxVal, max(danger[i][0], danger[i][1]));
        }

        dsu dsu(maxVal + 1);

        for (int i = 0; i < n; i++)
        {
            int a = mix[i][0], b = mix[i][1];
            bool flag = true;

            if (!dsu.Same(a, b))
            {
                for (auto p : danger)
                {
                    int x = p[0], y = p[1];

                    if ((dsu.Same(x, a) || dsu.Same(x, b)) && (dsu.Same(y , a) || dsu.Same(y, b)))
                    {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag)
            {
                ans[i] = "Yes";
                dsu.Merge(a, b);
            }
            else
            {
                ans[i] = "No";
            }
        }

        return ans;
    }
};