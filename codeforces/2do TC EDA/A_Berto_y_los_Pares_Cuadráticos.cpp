#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mid(l, r) ((l + r) / 2)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())

signed main()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    map<int, int> val;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        val[a[i] * i * i]++;
    }
    

    int ans = 0;

    for (auto num : val)
    {
        if (num.second > 1)
        {
            ans += num.second * (num.second - 1) / 2;
        }
    }

    cout << ans << endl;
}