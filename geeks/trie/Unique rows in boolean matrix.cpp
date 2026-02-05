#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

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
        tree.assign(1, vector<int>(26, -1));
        end.assign(1, false);
        count.assign(1, 0);
    }

    void insert(string word)
    {
        int current = 0;

        for (char c : word)
        {
            int index = c - 'a';

            if (tree[current][index] == -1)
            {
                tree[current][index] = nodes;
                tree.resize(nodes + 1, vector<int>(26, -1));
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
            int index = c - 'a';

            if (tree[current][index] == -1)
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
            int index = c - 'a';

            if (tree[current][index] == -1)
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
            int index = c - 'a';

            if (tree[current][index] == -1)
            {
                return 0;
            }

            current = tree[current][index];
        }

        return count[current];
    }
};

class Solution
{
public:
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
    {
        trie trie;
        vector<vector<int>> ans;

        for (int i = 0; i < row; i++)
        {
            string temp = "";
            vector<int> current(col);

            for (int j = 0; j < col; j++)
            {
                if (M[i][j])
                {
                    temp += 'b';
                }
                else
                {
                    temp += 'a';
                }

                current[j] = M[i][j];
            }

            if (!trie.search(temp))
            {
                trie.insert(temp);
                ans.push_back(current);
            }
        }

        return ans;
    }
};

signed main()
{
    Solution sol;

    int row = 4, col = 3;

    static int M[MAX][MAX] = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 1, 0},
        {1, 1, 0}};

    vector<vector<int>> result = sol.uniqueRow(M, row, col);

    for (const auto &r : result)
    {
        for (int val : r)
        {
            cout << val << " ";
        }

        cout << endl;
    }
}