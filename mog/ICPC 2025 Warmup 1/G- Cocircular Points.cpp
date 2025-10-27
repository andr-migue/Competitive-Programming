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

void Center(pii a,pii b,pii c)
{
    pii Pm1 = {(a.first + b.first) / 2, (a.second + b.second) / 2};
    pii Pm2 = {(b.first + c.first) / 2, (b.second + c.second) / 2};

    pii VN1 = {a.first - b.first, -(a.second - b.second)};
    pii VN2 = {b.first - c.first, -(b.second - c.second)};

    int A1 = VN1.second;
    int B1 = -VN1.first;
    int C1 = VN1.second * Pm1.first - VN1.first * Pm1.second;

    int A2 = VN2.second;
    int B2 = -VN2.first;
    int C2 = VN2.second * Pm2.first - VN2.first * Pm2.second;

    float Delta = A1 * B2 - A2 * B1;
    float DeltaX = C1 * B2 - A2 * C2;
    float DeltaY = A1 * C2-C2*
}
double Radio(pii cir, pii p)
{
    double radio;
    radio = sqrt((cir.first - p.first) * (cir.first - p.first) + (cir.second - p.second) * (cir.second - p.second));
    return radio;
}
int Circunscrito(vpii set, pii O, int R)
{
    int count = 0;
    for (int i = 0; i < size(set); i++)
    {
        if ((set[i].first - O.first) * (set[i].first - O.first) + (set[i].second - O.second) * (set[i].second - O.second) == R * R)
        {
            count++;
        }
    }
    return count - 3;
}
void solve()
{
}

signed main()
{
    int t;

    while (true)
    {
        cin >> t;
        if (t == 0)
        {
            break;
        }
        solve();
        cout << endl;
    }
}