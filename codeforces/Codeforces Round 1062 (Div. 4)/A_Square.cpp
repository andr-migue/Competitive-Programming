#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector<int> square(4);

    for (int i = 0; i < 4; i++)
    {
        cin >> square[i];
    }

    bool t = true;

    for (int i = 1; i < 4; i++)
    {
        if (square[i] != square[i - 1])
        {
            t = false;
            break;
        }
    }

    cout << t ? "YES" : "NO";
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