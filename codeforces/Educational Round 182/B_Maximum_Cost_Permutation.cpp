#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define int long long
#define size(x) (int)(x.size())
#define mid(L, R) ((L + R) / 2)
#define pb push_back
#define pf push_front
#define lb lower_bound
#define up upper_bound
#define fs first
#define sc second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vpii> vvpii;
typedef pair<vi, vi> pvv;

int mcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;

        b = a % b;
        a = temp;
    }

    return a;
}

int l, m, n, o, p, q, r, s, u, v, w, x, y, z;
string s1, s2;
char c;

void solve()
{
    cin >> n;
    vi a(n);
    int zeroPos = 0;
    int zero = 0;
    vb b(n);
    forn(i, n)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            zero++;
            zeroPos = i;
        }
        else
        {
            b[a[i] - 1] = true;
        }
    }

    int l = 0;
    int r = 0;
    int falta = 0;
    forn(i, n)
    {
        if (!b[i])
        {
            falta = i + 1;
            break;
        }
    }
    if (zero == 1)
    {
        a[zeroPos] = falta;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != i + 1)
        {
            l = i + 1;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] != i + 1)
        {
            r = i + 2;
            break;
        }
    }

    cout << r - l;
}

signed main()
{
    int t = 1;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
        cout << endl;
    }
}