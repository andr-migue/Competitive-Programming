#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mid(l, r) ((l + r) / 2)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

class trie
{
public:
    vector<vector<int>> tree;
    vector<bool> end;
    vector<int> count;
    vector<bool> isA;
    int nodes;

    trie()
    {
        tree.push_back(vector<int>(26, -1));
        end.push_back(false);
        count.push_back(0);
        isA.push_back(false);
        nodes = 1;
    }

    void insert(string &s, bool A)
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
                isA.push_back(A);
            }

            node = tree[node][i];
            isA[node] = A;
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

    vector<string> solve()
    {
        vector<string> ans;

        int node = 0;

        for (int i = 0; i < 26; i++)
        {
            if (tree[node][i] != -1)
            {
                string s = "";

                if (isA[tree[node][i]])
                {
                    s += i + 'a';
                    ans.push_back(s);
                    continue;
                }

                s += i + 'a';

                int current = tree[node][i];
                bool flag = false;

                while (current < nodes && !end[current])
                {
                    int index = -1;

                    for (int j = 0; j < 26; j++)
                    {
                        if (tree[current][j] != -1)
                        {
                            if (isA[tree[current][j]])
                            {
                                flag = true;
                            }

                            index = j;
                            break;
                        }
                    }

                    if (index != -1)
                    {
                        s += index + 'a';
                        current = tree[current][index];
                    }
                    
                    if (flag)
                    {
                        break;
                    }
                }

                if (flag)
                {
                    ans.push_back(s);
                }
            }
        }

        return ans;
    }

    int prefix_query(string &prefix)
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

signed main()
{
}