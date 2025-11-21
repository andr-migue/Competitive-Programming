#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mid(l, r) ((l + r) / 2)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) sort(v.rbegin(), v.rend())

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

bool coprimes(int a, int b)
{
    return mcd(a, b) == 1;
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