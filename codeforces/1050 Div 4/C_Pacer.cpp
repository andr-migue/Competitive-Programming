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
    cin >> n >> m;
    vpii a(n);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].fs;
        cin >> a[i].sc;
    }

    int k = a[0].fs;

    if (a[0].sc == 0)
    {
        ans += (k / 2) * 2;
    }

    else
    {
        ans += ((k - 1) / 2) * 2 + 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        k = a[i + 1].fs - a[i].fs;

        if (a[i].sc == a[i + 1].sc)
        {
            ans += (k / 2) * 2;
        }

        else
        {
            ans += ((k - 1) / 2) * 2 + 1;
        }
    }

    k = m - a[n - 1].fs;
    ans += k;

    cout << ans;
}

signed main()
{
    int t = 1;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
        cout << '\n';
    }
}