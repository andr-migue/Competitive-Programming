#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

class online_median
{
private:
    maxHeap maxHeap;
    minHeap minHeap;

    void balance()
    {
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

public:
    void insert(int value)
    {
        if (maxHeap.empty() || value < maxHeap.top())
        {
            maxHeap.push(value);
        }
        else
        {
            minHeap.push(value);
        }

        balance();
    }

    double getMedian()
    {
        if (maxHeap.empty())
        {
            return 0;
        }
        if (maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        else
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

class Solution
{
public:
    vector<double> getMedian(vector<int> &arr)
    {
        int n = arr.size();
        online_median median;
        vector<double> ans(n);

        for (int i = 0; i < n; i++)
        {
            median.insert(arr[i]);
            ans[i] = median.getMedian();
        }

        return ans;
    }
};
