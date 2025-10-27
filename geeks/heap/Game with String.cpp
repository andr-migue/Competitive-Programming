#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

class Solution
{
public:
    int minValue(string &s, int k)
    {
        maxHeap heap;
        map<char, int> frec;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            frec[s[i]]++;
        }
        
        for (auto pair : frec)
        {
            heap.push(pair.second);
        }
        
        while (k > 0 && heap.size() > 0)
        {
            int hz = heap.top();
            heap.pop();

            hz--;
            k--;

            if (hz > 0)
            {
                heap.push(hz);
            }
        }

        long long ans = 0;

        while (heap.size() > 0)
        {
            int hz = heap.top();
            heap.pop();
            
            ans += (long long)hz * hz;
        }

        return ans;
    }
};