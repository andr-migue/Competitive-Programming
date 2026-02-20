#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

class Solution
{
public:
    vector<int> kLargest(vector<int> &arr, int k)
    {
        maxHeap heap;
        vector<int> ans(k);

        for (int a : arr)
        {
            heap.push(a);
        }

        for (int i = 0; i < k; i++)
        {
            ans[i] = heap.top();
            heap.pop();
        }

        return ans;
    }
};