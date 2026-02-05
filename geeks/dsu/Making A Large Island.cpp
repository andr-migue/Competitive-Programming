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

bool IsValid(int n, int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < n;
}

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = (int)grid.size();
        int ans = 0;
        dsu dsu(n * n);

        int dirI[] = {1, -1, 0, 0};
        int dirJ[] = {0, 0, 1, -1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    for (int d = 0; d < 4; d++)
                    {
                        int newI = i + dirI[d];
                        int newJ = j + dirJ[d];

                        if (IsValid(n, newI, newJ) && grid[newI][newJ])
                        {
                            dsu.Merge(i * n + j, newI * n + newJ);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!grid[i][j])
                {
                    set<int> islands;

                    for (int d = 0; d < 4; d++)
                    {
                        int newI = i + dirI[d];
                        int newJ = j + dirJ[d];

                        if (IsValid(n, newI, newJ) && grid[newI][newJ])
                        {
                            islands.insert(dsu.SetOf(newI * n + newJ));
                        }
                    }

                    int size = 1;

                    for (int island : islands)
                    {
                        size += dsu.GetSize(island);
                    }

                    ans = max(ans, size);
                }
            }
        }

        if (ans == 0)
        {
            ans = n * n;
        }

        return ans;
    }
};

//signed main()
//{
//    int n;
//    cin >> n;
//
//    vector<vector<int>> grid(n, vector<int>(n));
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            cin >> grid[i][j];
//        }
//    }
//    
//    Solution sol;
//
//    int ans = sol.largestIsland(grid);
//
//    cout << ans << '\n';
//}