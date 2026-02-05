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

int m, n, o, p, q, s, u, v, w, x, y, z;
string s1, s2;
char c;

void solve()
{
    cin >> n;
    vi a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int s1 = 0;
    int s2 = 0;
    int s3 = 0;

    for (int l = 1; l < n - 1; l++)
    {
        for (int r = l + 1; r < n; r++)
        {
            s1 = 0;
            for (int i = 0; i < l; i++)
            {
                s1 += a[i];
            }
            s1 %= 3;

            s2 = 0;
            for (int i = l; i < r; i++)
            {
                s2 += a[i];
            }
            s2 %= 3;

            s3 = 0;
            for (int i = r; i < n; i++)
            {
                s3 += a[i];
            }
            s3 %= 3;

            if ((s1 == s2 && s2 == s3) || (s1 != s2 && s2 != s3 && s3 != s1))
            {
                cout << l << ' ' << r;
                return;
            }
        }
        
    }
    
    cout << 0 << ' ' << 0;
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