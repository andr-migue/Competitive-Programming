#include <bits/stdc++.h>

using namespace std;

#define int long long

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

    bool starts_with(string &prefix)
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
};


signed main()
{
    int n;
    cin >> n;

    trie trie;

    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        trie.insert(a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        string prefix;
        cin >> prefix;

        if (!trie.starts_with(prefix))
        {
            cout << '*' << endl;
        }

        else
        {
            int node = 0;

            for (char c : prefix)
            {
                int i = c - 'a';
                node = trie.tree[node][i];
            }

            while (node < trie.nodes && !trie.end[node])
            {
                int index = 0;

                for (int i = 0; i < 26; i++)
                {
                    if (trie.tree[node][i] != -1)
                    {
                        index = i;
                        break;
                    }
                }
                
                prefix += index + 'a';
                node = trie.tree[node][index];
            }

            cout << prefix << endl;
        }
    }
}