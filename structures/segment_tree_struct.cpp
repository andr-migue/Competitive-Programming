#include <bits/stdc++.h>

using namespace std;

struct node
{
    int sum, preffix, suffix, ans;
};

class segment_tree
{
public:
    int n;
    vector<node> tree;

    segment_tree(vector<int> arr)
    {
        n = arr.size();
        tree.resize(n);

        build(arr, 1, 0, n - 1);
    }

    node query(int left, int right)
    {
        return aux_query(1, 0, n - 1, left, right);
    }

    void update(int index, int value)
    {
        aux_update(1, 0, n - 1, index, value);
    }

private:
    void build(const vector<int> &arr, int node,int t_left, int t_right)
    {
        if (t_left == t_right)
        {
            tree[node] = make_node(arr[t_left]);
            return;
        }

        int mid = (t_left + t_right) / 2;

        build(arr, 2 * node, t_left, mid);
        build(arr, 2 * node + 1, mid + 1, t_right);

        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    node aux_query(int t_node, int t_left, int t_right, int left, int right)
    {
        if (right < t_left || t_right < left)
        {
            return make_node(0);
        }

        if (t_left == t_right)
        {
            return tree[t_node];
        }

        int mid = (t_left + t_right) / 2;

        node left_node = aux_query(2 * t_node, t_left, mid, left, right);
        node right_node = aux_query(2 * t_node + 1, mid + 1, t_right, left, right);

        return combine(left_node, right_node);
    }

    void aux_update(int node, int t_left, int t_right, int index, int value)
    {
        if (t_left == t_right)
        {
            tree[node] = make_node(value);
            return;
        }

        int mid = (t_left + t_right) / 2;

        if (index <= mid)
        {
            aux_update(2 * node, t_left, mid, index, value);
        }
        else
        {
            aux_update(2 * node, mid + 1, t_right, index, value);
        }

        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    node make_node(int value)
    {
        node leaf = node();

        leaf.sum = value;
        leaf.preffix = max(0, value);
        leaf.suffix = max(0, value);
        leaf.ans = max(0, value);

        return leaf;
    }

    node combine(node left, node right)
    {
        node ans = node();

        ans.sum = left.sum + right.sum;
        ans.preffix = max(left.preffix, left.sum + right.preffix);
        ans.suffix = max(right.suffix, right.sum + left.suffix);
        ans.ans = max(left.ans, right.ans, left.preffix + right.suffix);

        return ans;
    }
};