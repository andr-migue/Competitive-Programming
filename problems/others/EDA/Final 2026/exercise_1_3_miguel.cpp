#include <bits/stdc++.h>

using namespace std;

bool is_valid(int n, int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < n;
}

int solve(int n, const vector<vector<char>> &board, pair<int, int> start, pair<int, int> end)
{
    if (start == end) 
    {
        return 0;
    }

    auto [start_i, start_j] = start;
    auto [end_i, end_j] = end;

    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int,int>> bfs_q;

    dist[start_i][start_j] = 0;
    bfs_q.push({start_i, start_j});

    vector<int> dir_i = {1,  1, -1, -1};
    vector<int> dir_j = {1, -1,  1, -1};

    while (!bfs_q.empty()) 
    {
        auto [i, j] = bfs_q.front(); 
        bfs_q.pop();
        
        int new_d = dist[i][j] + 1;

        for (int d = 0; d < 4; ++d) 
        {
            int new_i = i + dir_i[d];
            int new_j = j + dir_j[d];

            while (is_valid(n, new_i, new_j) && board[new_i][new_j] == '.' && dist[new_i][new_j] == -1) 
            {
                dist[new_i][new_j] = new_d;
                
                if (new_i == end_i && new_j == end_j)
                {
                    return dist[new_i][new_j];
                }

                bfs_q.push({new_i, new_j});

                new_i += dir_i[d];
                new_j += dir_j[d];
            }
        }
    }

    return -1;
}

signed main()
{
}
