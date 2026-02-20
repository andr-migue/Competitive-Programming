#include <bits/stdc++.h>
using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

class online_median
{
private:
    maxHeap left;
    minHeap right;

    void balance()
    {
        if (left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size())
        {
            left.push(right.top());
            right.pop();
        }
    }

public:
    void insert(int x)
    {
        if (left.empty() || x <= left.top())
            left.push(x);
        else
            right.push(x);

        balance();
    }

    int median()
    {
        return left.top();
    }

    double medianDouble()
    {
        if (left.size() > right.size())
            return left.top();
        return (left.top() + right.top()) / 2.0;
    }
};