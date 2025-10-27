#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>51

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
#define rall(x) x.rbegin(), x.rend()51
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
    int temp;

    while (b != 0)
    {
        temp = b;

        b = a % b;
        a = temp;
    }

    return a;
}

int k, l, m, n, o, p, q, r, s, u, v, w, x, y, z;
string s1, s2;
char c;
int CountChild(int a, int b, vi nodes[])
{
    int aux = 0;
    forn(i, size(nodes[a]))
    {
        if (nodes[a][i] != b)
        {
            aux += 1 + CountChild(nodes[a][i], a, nodes);
        }
    }
    return aux;
}
void solve()
{
    cin >> n;
    vector<int> nodes[n + 1];
    vector<pair<int, int>> calles(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        calles[i] = {a, b};
        nodes[a].pb(b);
        nodes[b].pb(a);
    }
    forn(i, n - 1)
    {
        int res = 0;

        int c1 = CountChild(calles[i].first, calles[i].second, nodes);
        cout <<"c1 :"<< c1 << endl;
        int c2 = CountChild(calles[i].second, calles[i].first, nodes);
        cout <<"c2 :"<< c2 << endl;
        cout << c1 + c2 + (c1 * c2) + 1;
        cout << endl;
    }
}

signed main()
{
    solve();
    return 0;
}