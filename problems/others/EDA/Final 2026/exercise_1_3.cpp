#include <bits/stdc++.h>
#include "../../../../structures/undirected_graph.hpp"

using namespace std;
using namespace structures;

int solve(int n, const vector<vector<char>> &board, pair<int, int> start, pair<int, int> end)
{
    if (start == end)
    {
        return 0;
    }

    auto [start_i, start_j] = start;
    auto [end_i, end_j] = end;

    vector<vector<int>> diag1(n, vector<int>(n, -1));
    vector<vector<int>> diag2(n, vector<int>(n, -1));
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'P') continue;

            if (i > 0 && j > 0 && diag1[i - 1][j - 1] != -1)
                diag1[i][j] = diag1[i - 1][j - 1];
            else
                diag1[i][j] = count++;

            if (i > 0 && j < n - 1 && diag2[i - 1][j + 1] != -1)
                diag2[i][j] = diag2[i - 1][j + 1];
            else
                diag2[i][j] = count++;
        }
    }

    list_graph graph(n * n + count);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'P') continue;

            int cell = i * n + j;
            graph.connect(cell, n * n + diag1[i][j]);
            graph.connect(cell, n * n + diag2[i][j]);
        }
    }

    int start_node = start_i * n + start_j;
    int end_node   = end_i * n + end_j;

    vector<int> dist(graph.size(), -1);
    queue<int>  bfs_q;

    dist[start_node] = 0;
    bfs_q.push(start_node);

    while (!bfs_q.empty())
    {
        int node = bfs_q.front();
        bfs_q.pop();

        for (int adj : graph[node])
        {
            if (dist[adj] == -1)
            {
                dist[adj] = dist[node] + 1;

                if (adj == end_node)
                {
                    return dist[adj] / 2;
                }

                bfs_q.push(adj);
            }
        }
    }

    return -1;
}