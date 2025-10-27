#include <bits/stdc++.h>
using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

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

pair<vector<int>, bool> solve(vector<int> ids, vector<pair<int, int>> swaps)
{
    int n = ids.size();
    int m = swaps.size();

    dsu dsu(n);
    vector<pair<minHeap, minHeap>> aux(n); // Heap de elementos y Heap de índices.
    vector<bool> mask(n);

    for (int i = 0; i < m; i++)
    {
        auto pair = swaps[i];
        int a = pair.first, b = pair.second;

        dsu.Merge(a, b);

        if (!mask[a])
        {
            aux[dsu.SetOf(a)].first.push(ids[a]);
            aux[dsu.SetOf(a)].second.push(a);

            mask[a] = true;
        }

        if (!mask[b])
        {
            aux[dsu.SetOf(b)].first.push(ids[b]);
            aux[dsu.SetOf(b)].second.push(b);

            mask[b] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dsu.GetSize(i) > 0)
        {
            auto pair = aux[i];

            auto nums = pair.first;
            auto indexes = pair.second;

            while (nums.size() > 0)
            {
                int value = nums.top();
                nums.pop();

                int index = indexes.top();
                indexes.pop();

                ids[index] = value;
            }
        }
    }

    bool sorted = true;

    for (int i = 1; i < n; i++)
    {
        if (ids[i] < ids[i - 1])
        {
            sorted = false;
            break;
        }
    }
    

    return {ids, sorted};
}

signed main()
{
    vector<int> num = {4, 3, 2, 1};
    vector<pair<int, int>> swaps = {{0, 1}};

    auto ans = solve(num, swaps);
    auto vector = ans.first;

    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << " ";
    }

    cout << boolalpha << ans.second;
}