#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

class Solution
{
public:
    void nearlySorted(vector<int> &arr, int k)
    {
        int n = arr.size();
        minHeap heap;

        int size = min(k + 1, n);
        for (int i = 0; i < size; i++)
        {
            heap.push(arr[i]);
        }

        int current = 0;
        int next = k + 1;

        while (next < n)
        {
            arr[current++] = heap.top();
            heap.pop();
            heap.push(arr[next++]);
        }

        while (heap.size() > 0)
        {
            arr[current++] = heap.top();
            heap.pop();
        }
    }
};