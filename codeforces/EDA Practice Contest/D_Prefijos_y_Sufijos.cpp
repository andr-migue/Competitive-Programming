#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> prefix_function(const string &pat)
{
    int n = (int)pat.size();
    vector<int> pi(n);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];

        while (j > 0 && pat[i] != pat[j])
            j = pi[j - 1];

        if (pat[i] == pat[j])
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

    vector<int> pi = prefix_function(s);

    vector<int> pref;
    pref.push_back(n);
    int len = pi[n - 1];

    while (len > 0)
    {
        pref.push_back(len);
        len = pi[len - 1];
    }

    vector<int> hz(n + 1, 1);
    hz[0] = 0;

    for (int i = n; i > 0; i--)
    {
        int next = pi[i - 1];
        hz[next] += hz[i];
    }

    cout << pref.size() << endl;

    for (int i = pref.size() - 1; i >= 0; i--)
    {
        cout << pref[i] << " " << hz[pref[i]] << endl;
    }
}