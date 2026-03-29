#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        minHeap heap;

        for (auto row : mat)
        {
            for (auto num : row)
            {
                heap.push(num);
            }
        }

        for (int i = 0; i < k - 1; i++)
        {
            heap.pop();
        }

        return heap.top();
    }
};
