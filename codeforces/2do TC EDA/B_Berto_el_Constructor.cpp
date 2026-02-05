#include <bits/stdc++.h>

using namespace std;

#define int long long

bool isValid(int i, int j, int n, int m)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}

class dsu
{
public:
    vector<int> parent, size;
    stack<tuple<int, int, int, int>> history; // y, parent[y], size[x], islands
    int islands = 0;

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

        history.push({y, parent[y], size[x], islands});

        parent[y] = x;
        size[x] += size[y];
        islands--;

        return true;
    }

    void undo()
    {
        if (history.size() == 0)
        {
            return;
        }

        auto [y, parent_y, size_x, _islands] = history.top();
        history.pop();

        if (y == -1)
        {
            islands = _islands;
            return;
        }

        int x = parent[y];
        parent[y] = parent_y;
        size[x] = size_x;
        islands = _islands;
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

    void add_island()
    {
        history.push({-1, -1, -1, islands});
        islands++;
    }
};

signed main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> grid;

    for (int i = 0; i < n; i++)
    {
        vector<char> current(m);

        for (int j = 0; j < m; j++)
        {
            cin >> current[j];
        }

        grid.push_back(current);
    }

    dsu dsu(n * m);

    vector<int> dirI = {1, -1, 0, 0};
    vector<int> dirJ = {0, 0, 1, -1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '#')
            {
                dsu.add_island();

                for (int d = 0; d < 4; d++)
                {
                    int newI = i + dirI[d];
                    int newJ = j + dirJ[d];

                    if (isValid(newI, newJ, n, m) && grid[newI][newJ] == '#')
                    {
                        dsu.merge(i * m + j, newI * m + newJ);
                    }
                }
            }
        }
    }

    if (dsu.islands == k)
    {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                int check = dsu.checkpoint();

                dsu.add_island();

                for (int d = 0; d < 4; d++)
                {
                    int newI = i + dirI[d];
                    int newJ = j + dirJ[d];

                    if (isValid(newI, newJ, n, m) && grid[newI][newJ] == '#')
                    {
                        dsu.merge(i * m + j, newI * m + newJ);
                    }
                }

                if (dsu.islands == k)
                {
                    cout << "YES" << endl;
                    return 0;
                }

                dsu.rollback(check);
            }
        }
    }

    cout << "NO" << endl;
}