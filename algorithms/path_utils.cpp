#pragma once
#include <bits/stdc++.h>

using namespace std;

// Reconstructs the shortest path from start to target using previous[].
// Returns an empty vector if target is unreachable from start.
vector<int> reconstruct_path(const vector<int> &previous, int start, int target)
{
    vector<int> path;

    if (target != start && previous[target] == -1)
    {
        return path;
    }

    for (int node = target; node != -1; node = previous[node])
    {
        path.push_back(node);
    }

    reverse(path.begin(), path.end());
    return path;
}
