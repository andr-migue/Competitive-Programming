#include <bits/stdc++.h>

using namespace std;

class trie
{
public:
    int nodes;
    vector<vector<int>> tree;
    vector<bool> end;
    vector<int> count;
    vector<string> words;

    trie()
    {
        nodes = 1;
        tree.push_back(vector<int>(26, -1));
        end.push_back(false);
        count.push_back(0);
    }

    void insert(const string &s)
    {
        int node = 0;

        for (char c : s)
        {
            int index = c - 'a';

            if (tree[node][index] == -1)
            {
                tree[node][index] = nodes++;
                tree.push_back(vector<int>(26, -1));
                end.push_back(false);
                count.push_back(0);
            }

            node = tree[node][index];
            count[node]++;
        }

        end[node] = true;
        words.push_back(s);
    }

    bool searh(const string &s)
    {
        int node = 0;

        for (char c : s)
        {
            int index = c - 'a';

            if (tree[node][index] == -1)
            {
                return false;
            }

            node = tree[node][index];
        }

        return end[node];
    }

    bool starts_with(const string &prefix)
    {
        int node = 0;

        for (char c : prefix)
        {
            int index = c - 'a';

            if (tree[node][index] == -1)
            {
                return false;
            }

            node = tree[node][index];
        }

        return true;
    }

    bool prefix_query(const string &prefix)
    {
        int node = 0;

        for (char c : prefix)
        {
            int index = c - 'a';

            if (tree[node][index] == -1)
            {
                return 0;
            }

            node = tree[node][index];
        }

        return count[node];
    }

    vector<string> lexicographic_order()
    {
        words.clear();
        dfs(0, "");
        return words;
    }

    void dfs(int node, string current)
    {
        if (end[node])
        {
            words.push_back(current);
        }

        for (int i = 0; i < 26; i++)
        {
            if (tree[node][i] != -1)
            {
                char c = i + 'a';

                dfs(tree[node][i], current + c);
            }
        }
    }
};