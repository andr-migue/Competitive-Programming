#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    bool odd = false, even = false;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (a[i] % 2 == 0)
        {
            even = true;
        }
        else
        {
            odd = true;
        }
    }

    if (even && odd)
    {
        sort(a.begin(), a.end());
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
        cout << '\n';
    }
}