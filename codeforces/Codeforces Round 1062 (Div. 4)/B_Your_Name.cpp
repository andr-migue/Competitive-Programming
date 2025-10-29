#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> frecs(26);
    vector<int> frect(26);

    for (int i = 0; i < n; i++)
    {
        frecs[s[i] - 'a']++;
        frect[t[i] - 'a']++;
    }

    bool equal = true;
    
    for (int i = 0; i < 26; i++)
    {
        if (frecs[i] != frect[i])
        {
            equal = false;
            break;
        }
    }

    cout << equal ? "YES" : "NO";
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