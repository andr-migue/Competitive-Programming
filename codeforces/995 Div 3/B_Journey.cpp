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
    cin >> n >> o >> p >> q;
    int div = o + p + q;

    int b = n / div;

    if (b * div < n)
    {
        if (b * div + o < n)
        {
            if (b * div + o + p < n)
            {
                cout << b * 3 + 3;
                return;
            }

            cout << b * 3 + 2;
            return;
        }

        cout << b * 3 + 1;
        return;
    }

    cout << b * 3;
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