#include <bits/stdc++.h>

using namespace std;

#define int long long
#define size(x) (long long)(x.size())
#define mid(l, r) ((l + r) / 2)
#define forn(i, a, n) for (int i = a; i < n; i++)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) sort(v.rbegin(), v.rend())

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef set<int> si;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

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

int modpow(int base, int exp, int mod)
{
    int result = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

void solve()
{
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
        cout << '\n';
    }
}