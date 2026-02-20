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

bool IsValid(int n, int m, int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

class Solution
{
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        int oper = operators.size();
        vector<int> ans(oper);
        vector<vector<int>> grid(n, vector<int>(m));

        dsu dsu(n * m);
        int islands = 0;

        int dirI[] = {1, -1, 0, 0};
        int dirJ[] = {0, 0, 1, -1};

        for (int o = 0; o < oper; o++)
        {
            int a = operators[o][0], b = operators[o][1];

            if (grid[a][b])
            {
                ans[o] = islands;
            }
            else
            {
                grid[a][b] = 1;
                islands++;

                for (int d = 0; d < 4; d++)
                {
                    int newI = a + dirI[d];
                    int newJ = b + dirJ[d];

                    if (IsValid(n, m, newI, newJ) && grid[newI][newJ])
                    {
                        if (dsu.Merge(a * m + b, newI * m + newJ))
                        {
                            islands--;
                        }
                    }
                }

                ans[o] = islands;
            }
        }

        return ans;
    }
};