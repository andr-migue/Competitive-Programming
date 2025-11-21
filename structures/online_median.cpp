#include <bits/stdc++.h>
using namespace std;

class online_median
{
private:
    priority_queue<int> maxHeap;                            
    priority_queue<int, vector<int>, greater<int>> minHeap; 

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