#include <bits/stdc++.h>

using namespace std;

#define int long long

class node
{
public:
    int value;
    int end;
    node *arr[2];

    node()
    {
        value = 0;
        end = 0;
        arr[0] = nullptr;
        arr[1] = nullptr;
    }
};

class binary_trie
{
private:
    const int n = 32;

public:
    node root;

    binary_trie()
    {
        root = node();
    }

    void insert(int number)
    {
        node *current = &root;

        for (int i = n - 1; i >= 0; i--)
        {
            int bit = (number >> i) & 1;

            if (!current->arr[bit])
            {
                current->arr[bit] = new node();
            }

            current = current->arr[bit];
        }

        current->value = number;
        current->end++;
    }

    bool erase(int number)
    {
        if (!search(number))
        {
            return false;
        }

        vector<pair<node *, int>> path;
        node *current = &root;

        path.push_back({current, -1});

        for (int i = n - 1; i >= 0; i--)
        {
            int bit = (number >> i) & 1;
            path.push_back({current, bit});
            current = current->arr[bit];
        }

        current->end--;

        if (current->end == 0)
        {
            for (int i = path.size() - 1; i > 0; i--)
            {
                node *parent = path[i].first;
                int bit = path[i].second;
                node *child = parent->arr[bit];

                if (child && child->end == 0 && !child->arr[0] && !child->arr[1])
                {
                    delete child;
                    parent->arr[bit] = nullptr;
                }
                else
                {
                    break;
                }
            }
        }

        return true;
    }

    bool search(int number)
    {
        node *current = &root;

        for (int i = n - 1; i >= 0; i--)
        {
            int bit = (number >> i) & 1;

            if (!current->arr[bit])
            {
                return false;
            }

            current = current->arr[bit];
        }

        return current->end > 0;
    }

    int max_xor(int number)
    {
        node *current = &root;

        for (int i = n - 1; i >= 0; i--)
        {
            int bit = (number >> i) & 1;

            if (current->arr[1 - bit])
            {
                current = current->arr[1 - bit];
            }
            else if (current->arr[bit])
            {
                current = current->arr[bit];
            }
        }

        return number xor current->value;
    }
};

signed main()
{
    int q;
    char qi;
    int x;
    cin >> q;

    binary_trie trie;
    trie.insert(0);

    while (q--)
    {
        cin >> qi >> x;

        if (qi == '+')
        {
            trie.insert(x);
        }
        else if (qi == '-')
        {
            trie.erase(x);
        }
        else
        {
            cout << trie.max_xor(x) << endl;
        }
    }
}