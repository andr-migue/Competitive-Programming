#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        int ans = 0;
        minHeap heap;

        for (int a : arr)
        {
            heap.push(a);
        }

        while (heap.size() > 1)
        {
            int a = heap.top();
            heap.pop();

            int b = heap.top();
            heap.pop();

            int cost = a + b;
            ans += cost;

            heap.push(cost);
        }

        return ans;
    }
};