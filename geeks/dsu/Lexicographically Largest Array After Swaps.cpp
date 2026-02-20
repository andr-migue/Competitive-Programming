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

vector<int> solve(vector<int> num, vector<pair<int, int>> swaps)
{
    int n = num.size();
    int m = swaps.size();

    dsu dsu(n);
    vector<pair<maxHeap, minHeap>> children(n);
    vector<bool> mask(n);

    for (int i = 0; i < m; i++)
    {
        int a = swaps[i].first, b = swaps[i].second;
        dsu.Merge(a, b);
    }

    for (int i = 0; i < m; i++)
    {
        int a = swaps[i].first, b = swaps[i].second;

        if (!mask[a])
        {
            children[dsu.SetOf(a)].first.push(num[a]);
            children[dsu.SetOf(a)].second.push(a);
            mask[a] = true;
        }
        if (!mask[b])
        {
            children[dsu.SetOf(b)].first.push(num[b]);
            children[dsu.SetOf(b)].second.push(b);
            mask[b] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dsu.GetSize(i) > 0)
        {
            auto maxHeap = children[i].first;
            auto minHeap = children[i].second;

            while (maxHeap.size() > 0)
            {
                int value = maxHeap.top();
                maxHeap.pop();

                int index = minHeap.top();
                minHeap.pop();

                num[index] = value;
            }
            
        }
    }

    return num;
}

signed main()
{
    vector<int> num = {1, 3, 4, 5};
    vector<pair<int, int>> swaps = {{0, 1}, {2, 3}};

    auto ans = solve(num, swaps);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}