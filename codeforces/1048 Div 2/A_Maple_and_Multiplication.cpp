#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define int long long
#define size(x) (int)(x.size())
#define mid(L, R) ((L + R) / 2)
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
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
    int a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << 0;
        return;
    }

    if (a % b == 0 || b % a == 0)
    {
        cout << 1;
        return;
    }

    else
    {
        cout << 2;
        return;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    forn(i, t)
    {
        solve();
        cout << '\n';
    }
}