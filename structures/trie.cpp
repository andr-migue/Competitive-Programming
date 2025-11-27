#include <bits/stdc++.h>

using namespace std;

class trie
{
public:
    vector<vector<int>> tree;
    vector<bool> end;
    vector<int> count;
    int nodes;

    trie()
    {
        tree.push_back(vector<int>(26, -1));
        end.push_back(false);
        count.push_back(0);
        nodes = 1;
    }

    void insert(string &s)
    {
        int node = 0;

        for (char c : s)
        {
            int i = c - 'a';

            if (tree[node][i] == -1)
            {
                tree[node][i] = nodes++;
                tree.push_back(vector<int>(26, -1));
                end.push_back(false);
                count.push_back(0);
            }

            node = tree[node][i];
            count[node]++;
        }

        end[node] = true;
    }

    bool search(string &s)
    {
        int node = 0;

        for (char c : s)
        {
            int i = c - 'a';

            if (tree[node][i] == -1)
                return false;

            node = tree[node][i];
        }

        return end[node];
    }

    bool startsWith(string &prefix)
    {
        int node = 0;

        for (char c : prefix)
        {
            int i = c - 'a';

            if (tree[node][i] == -1)
                return false;

            node = tree[node][i];
        }

        return true;
    }

    int countPrefix(string &prefix)
    {
        int node = 0;

        for (char c : prefix)
        {
            int i = c - 'a';

            if (tree[node][i] == -1)
                return 0;

            node = tree[node][i];
        }

        return count[node];
    }
};
