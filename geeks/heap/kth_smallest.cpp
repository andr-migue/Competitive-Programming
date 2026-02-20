#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        maxHeap heap;

        for (int i = 0; i < arr.size(); i++)
        {
            if (heap.size() == k)
            {
                if (heap.top() > arr[i])
                {
                    heap.pop();
                    heap.push(arr[i]);
                }
            }

            else
            {
                heap.push(arr[i]);
            }
        }

        return heap.top();
    }
};