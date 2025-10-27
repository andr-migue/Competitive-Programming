#include <bits/stdc++.h>

using namespace std;

#define int long long
#define size(x) (long long)(x.size())
#define mid(l, r) ((l + r) / 2)

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
    int temp;

    while (b != 0)
    {
        temp = b;

        b = a % b;
        a = temp;
    }

    return a;
}

int tc, l, r, k, m, n, o, p, q, s, t, u, v, w, x, y, z;
string s1, s2;
char c;

void solve()
{
    cin >> n;

    cout << 2 * n - 2;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;

    while (tc--)
    {
        solve();
        cout << '\n';
    }
}