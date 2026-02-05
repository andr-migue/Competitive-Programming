#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

class Solution
{
public:
    vector<int> mergeArrays(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> ans(n * m);
        minHeap heap;

        for (auto row : mat)
        {
            for (auto num : row)
            {
                heap.push(num);
            }
        }

        for (int i = 0; i < n * m; i++)
        {
            ans[i] = heap.top();
            heap.pop();
        }

        return ans;
    }
};