#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<int> maxHeap;

vector<int> solve(const vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> ans(n - k + 1);

    map<int, int> freq;
    set<pair<int, int>> s;

    for (int i = 0; i < k; i++)
    {
        if (freq[arr[i]] > 0)
        {
            s.erase({-freq[arr[i]], arr[i]});
        }

        freq[arr[i]]++;
        s.insert({-freq[arr[i]], arr[i]});
    }

    ans[0] = s.begin()->second;

    for (int i = 1; i < n - k + 1; i++)
    {
        int out = arr[i - 1];
        int in = arr[i + k - 1];

        if (freq[out] > 0)
        {
            s.erase({-freq[out], out});
        }

        freq[out]--;
        if (freq[out] > 0)
        {
            s.insert({-freq[out], out});
        }

        if (freq[in] > 0)
        {
            s.erase({-freq[in], in});
        }

        freq[in]++;
        s.insert(-freq[in], in);

        ans[i] = s.begin()->second;
    }

    return ans;
}

signed main()
{
    
}