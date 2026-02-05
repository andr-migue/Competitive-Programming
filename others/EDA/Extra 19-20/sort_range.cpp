#include <bits/stdc++.h>

using namespace std;

#define mid(l, r) ((l + r) / 2)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

void sort_range(vector<int> &arr, int i, int j)
{
    if (j - i + 1 == 2 && arr[i] > arr[j])
    {
        swap(arr[i], arr[j]);
    }

    if (j - i + 1 >= 3)
    {
        int k = (j - i + 1) / 3;

        sort_range(arr, i, j - k);
        sort_range(arr, i + k, j);
        sort_range(arr, i, j - k);
    }
}

signed main()
{
    vector<int> arr = {2, 5, 3, 6, 9, 7};

    sort_range(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    
}