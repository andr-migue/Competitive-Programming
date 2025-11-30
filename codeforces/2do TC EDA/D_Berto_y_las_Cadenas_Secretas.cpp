#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mid(l, r) ((l + r) / 2)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())

vector<int> prefix_function(const string &s)
{
    int n = s.size();
    vector<int> pi(n);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }

    return pi;
}

signed main()
{
    string s;
    cin >> s;
    int n = s.size();

    auto pi = prefix_function(s);

    map<int, int> freq;

    for (int i = 0; i < n - 1; i++)
    {
        freq[pi[i]]++;
    }

    int l = pi[n - 1];
    int ans = 0;

    while (l > 0)
    {
        if (freq[l] > 0)
        {
            ans++;
        }

        l = pi[l - 1];
    }

    cout << ans << endl;
}