#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mid(l, r) ((l + r) / 2)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

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

bool isValid(int i, int j, int n, int m)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}

int solve(const vector<vector<char>> &matrix, int n, int m)
{
    vector<int> dirI = {1, -1, 0, 0};
    vector<int> dirJ = {0, 0, 1, -1};

    dsu dsu(n * m);

    int max_island = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '#')
            {
                for (int d = 0; d < 4; d++)
                {
                    int newI = i + dirI[d];
                    int newJ = j + dirJ[d];

                    if (isValid(newI, newJ, n, m) && matrix[newI][newJ] == '#')
                    {
                        dsu.merge(i * m + j, newI * m + newJ);
                    }
                }

                int size = dsu.get_size(i * m + j);

                if (size > max_island)
                {
                    max_island = size;
                }
            }
        }
    }

    vector<int> diagI = {1, -1,   1, -1};
    vector<int> diagJ = {1,  1,  -1, -1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == ' ')
            {
                int check = dsu.checkpoint();

                int spaces = 0;

                for (int d = 0; d < 4; d++)
                {
                    int newI = i + dirI[d];
                    int newJ = j + dirJ[d];

                    if (isValid(newI, newJ, n, m) && matrix[newI][newJ] == ' ')
                    {
                        spaces++;
                        dsu.merge(i * m + j, newI * m + newJ);

                        int newI2 = newI + dirI[d];
                        int newJ2 = newJ + dirJ[d];

                        if (isValid(newI2, newJ2, n, m) && matrix[newI2][newJ2] == '#')
                        {
                            dsu.merge(newI2 * m + newJ2, newI * m + newJ);
                        }
                    }
                }

                if (spaces == 4)
                {
                    for (int d = 0; d < 4; d++)
                    {
                        int newI = i + diagI[d];
                        int newJ = j + diagJ[d];

                        if (isValid(newI, newJ, n, m) && matrix[newI][newJ] == '#')
                        {
                            dsu.merge(i * m + j, newI * m + newJ);
                        }
                    }

                    int size = dsu.get_size(i * m + j);

                    if (size > max_island)
                    {
                        max_island = size;
                    }
                }

                dsu.rollback(check);
            }
        }
    }

    return max_island;
}

signed main()
{
    vector<vector<char>> matrix =  {{'#', ' ', '#'},
                                    {' ', ' ', ' '},
                                    {'#', ' ', '#'}};
    int n = 3;
    int m = 3;

    cout << solve(matrix, n, m);
}