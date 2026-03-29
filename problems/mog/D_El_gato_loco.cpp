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

int l, m, n, o, p, q, r, s, u, v, w, x, y, z;
string s1, s2;

map<pair<char, char>, char> mp;
map<string, char> mps;

signed main()
{
    cin >> s1 >> s2;
    string ans = "";

    mp[{'h', 'p'}] = 'q';
    mp[{'v', 'p'}] = 'b';
    mp[{'r', 'p'}] = 'd';

    mp[{'h', 'b'}] = 'd';
    mp[{'v', 'b'}] = 'p';
    mp[{'r', 'b'}] = 'q';

    mp[{'h', 'q'}] = 'p';
    mp[{'v', 'q'}] = 'd';
    mp[{'r', 'q'}] = 'b';

    mp[{'h', 'd'}] = 'b';
    mp[{'v', 'd'}] = 'q';
    mp[{'r', 'd'}] = 'p';

    mps[{"hv"}] = 'r';
    mps[{"vh"}] = 'r';
    mps[{"rh"}] = 'v';
    mps[{"hr"}] = 'v';
    mps[{"vr"}] = 'h';
    mps[{"rv"}] = 'h';

    char laTranca = s2[0];

    bool rot = false;
    bool flag = false;
    forn(i, size(s2))
    {
        if (s2[i] != 'v')
        {
            rot = !rot;
        }
    }
    if (s2.length() == 0)
    {
        cout << s1;
        return 0;
    }
    else if (s2.length() > 1)
    {
        for (int i = 1; i < size(s2); i++)
        {
            if (laTranca == s2[i])
            {
                flag = true;
            }
            else
            {
                if (flag)
                {
                    laTranca = s2[i];

                    flag = false;
                }
                else
                {
                    string cas = "";

                    cas += laTranca;
                    cas += s2[i];
                    laTranca = mps[cas];
                }
            }
        }
    }

    if (rot)
    {
        for (int i = s1.length() - 1; i >= 0; i--)
        {
            ans += mp[{laTranca, s1[i]}];
        }
    }
    else if (!flag)
    {
        for (int i = 0; i < s1.length(); i++)
        {
            ans += mp[{laTranca, s1[i]}];
        }
    }
    else
    {

        for (int i = 0; i < s1.length(); i++)
        {
            ans += s1[i];
        }
    }
    cout << ans;
}