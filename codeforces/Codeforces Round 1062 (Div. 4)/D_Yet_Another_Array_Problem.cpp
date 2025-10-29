#include <bits/stdc++.h>

using namespace std;
#define int long long

int mcd(int a, int b)
{
    int temp;

    while (b != 0)
    {
        temp = b;

        b = a % b;
        a = temp;
    }

    return a;
}

bool coprimes(int a, int b)
{
    return mcd(a, b) == 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int x = 2; x <= 1000000000000000000; x++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coprimes(x, a[j]))
            {
                cout << x;
                return;
            }
        }
    }

    cout << -1;
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