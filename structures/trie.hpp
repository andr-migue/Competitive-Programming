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
        nodes = 1;
        tree.assign(1, vector<int>(52, -1));
        end.assign(1, false);
        count.assign(1, 0);
    }

    int getIndex(char c)
    {
        if (c >= 'a' && c <= 'z')
            return c - 'a'; // 0-25 para minúsculas
        else if (c >= 'A' && c <= 'Z')
            return c - 'A' + 26; // 26-51 para mayúsculas
        else
            return -1; // Carácter inválido
    }

    void insert(string word)
    {
        int current = 0;

        for (char c : word)
        {
            int index = getIndex(c);

            if (index < 0 || index >= 52)
                continue;

            if (tree[current][index] == -1)
            {
                tree[current][index] = nodes;
                tree.resize(nodes + 1, vector<int>(52, -1));
                end.resize(nodes + 1, false);
                count.resize(nodes + 1, 0);
                nodes++;
            }

            current = tree[current][index];
            count[current]++;
        }

        end[current] = true;
    }

    bool search(string word)
    {
        int current = 0;

        for (char c : word)
        {
            int index = getIndex(c);

            if (index < 0 || index >= 52 || tree[current][index] == -1)
            {
                return false;
            }

            current = tree[current][index];
        }

        return end[current];
    }

    bool startsWith(string prefix)
    {
        int current = 0;

        for (char c : prefix)
        {
            int index = getIndex(c);

            if (index < 0 || index >= 52 || tree[current][index] == -1)
            {
                return false;
            }

            current = tree[current][index];
        }

        return true;
    }

    int countWords(string prefix)
    {
        int current = 0;

        for (char c : prefix)
        {
            int index = getIndex(c);

            if (index < 0 || index >= 52 || tree[current][index] == -1)
            {
                return 0;
            }

            current = tree[current][index];
        }

        return count[current];
    }
};