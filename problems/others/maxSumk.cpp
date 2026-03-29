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
    int n, k;

    cin >> n >> k;

    if (n < k)
    {
        cout << 0 << endl;
        return;
    }

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        ans += arr[i];
    }

    int current = ans;

    for (int i = k; i < n; i++)
    {
        current += arr[i];
        current -= arr[i - k];

        ans = max(current, ans);
    }

    cout << ans << endl;
}