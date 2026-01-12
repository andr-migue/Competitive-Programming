#include <bits/stdc++.h>

using namespace std;

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

    int binary_search(vector<int> Mx, int k)
    {
        int i = 0;
        int j = Mx.size() - 1;

        while (i <= j)
        {
            int mid = (i + j) / 2;

            if (Mx[mid] >= k)
            {
                j = mid;
            }
            else
            {
                i = mid + 1;
            }
        }

        return i;
    }
};

signed main()
{
    vector<int> arr = {0, 0, 2, 3, 0};
    segment_tree tree(arr);

    cout << tree.query(0, 4);
}