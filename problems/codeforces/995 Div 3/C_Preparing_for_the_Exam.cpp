#include <bits/stdc++.h>

using namespace std;

#define int long long
#define size(x) (int)(x.size())
#define mid(L, R) ((L + R) / 2)
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back

typedef vector<int> vi;
typedef set<int> si;

int k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
string s1, s2;
char c;

void solve()
{
    cin >> n >> m >> k;

    vi exams(m);
    si set;

    for (int i = 0; i < m; i++)
    {
        cin >> exams[i];
    }

    for (int i = 0; i < k; i++)
    {
        cin >> x;
        set.insert(x);
    }

    if (k == n)
    {
        for (int i = 0; i < m; i++)
        {
            cout << 1;
        }

        return;
    }

    if (n - k > 1)
    {
        for (int i = 0; i < m; i++)
        {
            cout << 0;
        }

        return;
    }

    int missProblem;

    for (int i = 1; i <= n; i++)
    {
        if (!set.count(i))
        {
            missProblem = i;
            break;
        }
    }
    

    for (int i = 0; i < m; i++)
    {
        if (exams[i] == missProblem)
        {
            cout << 1;
        }

        else
        {
            cout << 0;
        }
    }
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