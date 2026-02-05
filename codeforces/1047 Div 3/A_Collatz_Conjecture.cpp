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

int k, l, m, n, o, p, q, r, s, u, v, w, x, y, z;
string s1, s2;
char c;

void recursiveSolve(int x, int k, bool &found)
{
    if (found)
    {
        return;
    }

    if (k == 0)
    {
        cout << x;
        found = true;
        return;
    }

    if ((x - 1) % 3 == 0)
    {
        int prevX = (x - 1) / 3;

        if (prevX % 2 != 0)
        {
            recursiveSolve(prevX, k - 1, found);
        }
    }

    if (!found)
    {
        recursiveSolve(x * 2, k - 1, found);
    }
}

void solve()
{
    cin >> k >> x;
    bool found = false;
    recursiveSolve(x, k, found);
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