#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper") // Enable AVX

using namespace std;

/// Macros
#define int long long
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define fs first
#define sc second
#define pf push_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x.size())
#define mid ((L + R) / 2)
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order
// order_of_key

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vpii> vvpii;
typedef pair<vi, vi> pvv;
// typedef unordered_map<int,int,custom_hash> umii;
typedef map<int, int> mii;
typedef map<pii, int> mpiii;
typedef map<int, pii> mipii;
typedef __int128_t int128;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;

/// Constraints:
const int inf = ((1ll << 31ll) - 1ll);
const long long INF = (((1ll << 60ll) - 1ll) * 2ll) + 1ll;

const ld pi = acos(-1);
const ld eps = 1e-8;
const long long MAXN = 200005;

/// Functions:
#define lg2(x) 31 - __builtin_clz(x)
#define lg2ll(x) 63ll - __builtin_clzll(x)
#define lgx(x, b) (log(x) / log(b))

// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int mod = (119 << 23) + 1;

// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
/// Optimized power
int opow(int a, int b)
{
    int ans = 1;
    for (; b; b /= 2, a = (a * a) % mod)
    {
        if (b % 2)
        {
            ans = (ans * a) % mod;
        }
    }
    return ans;
}

/// Modular Inverse
int InverM(int a, int b)
{
    int inv = a % b;
    if (inv == 0)
        return 0;
    int ans = (1 - (int128)b * InverM(b, inv)) / inv;
    if (ans < 0)
        ans += b;
    return ans;
}

/// Eratostenes Crib
vector<int> P;
int Crib[MAXN];
void Prec()
{
    P.pb(2);

    for (int i = 2; i < MAXN; i += 2)
    {
        Crib[i] = 2;
    }

    for (int i = 3; i < MAXN; i += 2)
        if (!Crib[i])
        {
            P.pb(i);
            for (int j = i; j < MAXN; j += i)
                Crib[j] = i;
        }
}

/// Divisors
vi Divs(int n)
{
    vector<int> divs;
    for (int x = 1; x * x <= n; x++)
    {
        if (n % x == 0)
        {
            divs.push_back(x);
            divs.push_back(n / x);
        }
    }
    sort(divs.begin(), divs.end());
    divs.resize(unique(all(divs)) - divs.begin());
    return divs;
}

int l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
string s1, s2;
char c;

void solve()
{
}

signed main()
{
    int t;
    cin >> t;

    forn(i, t)
    {
        solve();
        cout << '\n';
    }
}