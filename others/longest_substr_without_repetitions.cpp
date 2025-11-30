#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mid(l, r) ((l + r) / 2)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

signed main()
{
    string s;
    cin >> s;

    int n = s.size();
    map<char, int> index;
    int ans = 0;
    int left = 0;

    for (int right = 0; right < n; right++)
    {
        if (index.find(s[right]) != index.end() && index[s[right]] >= left)
        {
            left = index[s[right]] + 1;
        }

        index[s[right]] = right;
        ans = max(ans, right - left + 1);
    }

    cout << ans << endl;
}