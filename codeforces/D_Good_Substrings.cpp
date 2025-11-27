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

    int goods(int node, int badCount, int k, vector<int> &bad)
    {
        int ans = 0;

        for (int c = 0; c < 26; c++)
        {
            if (tree[node][c] != -1)
            {
                int newBad = badCount + bad[c];

                if (newBad <= k)
                {
                    ans++;
                    ans += goods(tree[node][c], newBad, k, bad);
                }
            }
        }

        return ans;
    }
};

signed main()
{
    string s, bits;
    int k;
    trie trie;

    cin >> s >> bits >> k;

    for (int i = 0; i < (int)s.size(); i++)
    {
        string suffix = s.substr(i);
        trie.insert(suffix);
    }

    vector<int> bad(26);

    for (int i = 0; i < 26; i++)
    {
        if (bits[i] == '0')
        {
            bad[i] = 1;
        }
        else
        {
            bad[i] = 0;
        }
    }

    cout << trie.goods(0, 0, k, bad) << endl;
}