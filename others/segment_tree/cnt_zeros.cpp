#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mid(l, r) ((l + r) / 2)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

class segment_tree
{
public:
    int n;
    vector<int> tree;

    segment_tree(const vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);

        build(arr, 1, 0, n - 1);
    }

    int query(int left, int right)
    {
        return aux_query(1, 0, n - 1, left, right);
    }

    void update(int index, int value)
    {
        aux_update(1, 0, n - 1, index, value);
    }

    int find_kth_zero(int k)
    {
        return find(k, 1, 0, n - 1);
    }

private:
#define operation(a, b) a + b
    int neutral = 0;

    void build(const vector<int> &arr, int node, int t_left, int t_right)
    {
        if (t_left == t_right)
        {
            if (arr[t_left] == 0)
            {
                tree[node] = 1;
            }
            return;
        }

        int mid = (t_left + t_right) / 2;

        build(arr, 2 * node, t_left, mid);
        build(arr, 2 * node + 1, mid + 1, t_right);

        tree[node] = operation(tree[2 * node], tree[2 * node + 1]);
    }

    int aux_query(int node, int t_left, int t_right, int left, int right)
    {
        if (right < t_left || t_right < left)
        {
            return neutral;
        }

        if (left <= t_left && t_right <= right)
        {
            return tree[node];
        }

        int mid = (t_left + t_right) / 2;

        return operation(aux_query(2 * node, t_left, mid, left, right), aux_query(2 * node + 1, mid + 1, t_right, left, right));
    }

    void aux_update(int node, int t_left, int t_right, int index, int value)
    {
        if (t_left == t_right)
        {
            if (value == 0)
            {
                tree[node] = 1;
            }
            return;
        }

        int mid = (t_left + t_right) / 2;

        if (index <= mid)
        {
            aux_update(2 * node, t_left, mid, index, value);
        }
        else
        {
            aux_update(2 * node + 1, mid + 1, t_right, index, value);
        }

        tree[node] = operation(tree[2 * node], tree[2 * node + 1]);
    }

    int find(int k, int node, int t_left, int t_right)
    {
        if (k > tree[node])
        {
            return -1;
        }

        if (t_left == t_right)
        {
            return t_left;
        }

        int mid = (t_left + t_right) / 2;

        if (tree[2 * node] >= k)
        {
            return find(k, 2 * node, t_left, mid);
        }
        else
        {
            return find(k - tree[2 * node], 2 * node + 1, mid + 1, t_right);
        }
    }
};

signed main()
{
    vector<int> arr = {0, 0, 0, 0, 0};
    segment_tree tree(arr);

    cout << tree.query(0, 4) << " " << tree.find_kth_zero(5);
}
