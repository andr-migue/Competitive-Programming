#include <bits/stdc++.h>

using namespace std;

#define int long long
#define size(x) (int)(x.size())
#define mid(L, R) ((L + R) / 2)
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef vector<int> vi;

int l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
string s1, s2;
char c;

void solve()
{
    cin >> n;

    vi a(n);
    vi b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    if (n == 1)
    {
        cout << a[0];
        return;
    }

    int dif = 0;
    
    for (int i = 0; i <= n - 2; i++)
    {
        if (dif < dif + a[i] - b[i + 1])
        {
            dif += a[i] - b[i + 1];
        }
    }

    cout << dif + a[n - 1];
}

signed main()
{
    int t = 1;
    cin >> t;

    forn(i, t)
    {
        solve();
        cout << '\n';
    }
}