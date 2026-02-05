#include <bits/stdc++.h>

using namespace std;

class binary_trie
{
public:
    vector<array<int, 2>> tree;
    vector<int> count;
    vector<int> value;
    int nodes;
    int bits;

    binary_trie(int maxBits = 32)
    {
        bits = maxBits;
        tree.push_back({-1, -1});
        count.push_back(0);
        value.push_back(0);
        nodes = 1;
    }

    void insert(int x)
    {
        int node = 0;

        for (int i = bits - 1; i >= 0; i--)
        {
            int bit = (x >> i) & 1;

            if (tree[node][bit] == -1)
            {
                tree[node][bit] = nodes++;
                tree.push_back({-1, -1});
                count.push_back(0);
                value.push_back(0);
            }

            node = tree[node][bit];
            count[node]++;
        }

        value[node] = x;
    }

    void erase(int x)
    {
        int node = 0;

        for (int i = bits - 1; i >= 0; i--)
        {
            int bit = (x >> i) & 1;
            node = tree[node][bit];
            count[node]--;
        }
    }

    bool search(int x)
    {
        int node = 0;

        for (int i = bits - 1; i >= 0; i--)
        {
            int bit = (x >> i) & 1;

            if (tree[node][bit] == -1 || count[tree[node][bit]] == 0)
                return false;

            node = tree[node][bit];
        }

        return true;
    }

    int maxXor(int x)
    {
        int node = 0;

        for (int i = bits - 1; i >= 0; i--)
        {
            int bit = (x >> i) & 1;

            if (tree[node][1 - bit] != -1 && count[tree[node][1 - bit]] > 0)
                node = tree[node][1 - bit];
            else
                node = tree[node][bit];
        }

        return x ^ value[node];
    }

    int minXor(int x)
    {
        int node = 0;

        for (int i = bits - 1; i >= 0; i--)
        {
            int bit = (x >> i) & 1;

            if (tree[node][bit] != -1 && count[tree[node][bit]] > 0)
                node = tree[node][bit];
            else
                node = tree[node][1 - bit];
        }

        return x ^ value[node];
    }
};
