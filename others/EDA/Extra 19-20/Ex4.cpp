#include <bits/stdc++.h>

using namespace std;

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

bool solve(const string &W, const string &S)
{
    int n = W.size();
    int m = S.size();

    vector<int> prefix_aux = prefix_function(W + '$' + S);
    vector<int> pref(m);

    for (int i = 0; i < m; i++)
    {
        pref[i] = prefix_aux[i + n + 1];
    }

    string rev_W(W.rbegin(), W.rend());
    string rev_S(S.rbegin(), S.rend());

    vector<int> suffix_aux = prefix_function(rev_W + '$' + rev_S);
    vector<int> suff(m);

    for (int i = 0; i < m; i++)
    {
        suff[i] = suffix_aux[n + 1 + i];
    }

    reverse(suff.begin(), suff.end());

    int max_pref = 0;

    for (int i = 0; i < m; i++)
    {
        if (pref[i] > max_pref)
        {
            max_pref = pref[i];
        }

        if (max_pref + suff[i] >= n)
        {
            return true;
        }
    }

    return false;
}

signed main()
{
    cout << solve("abc", "abyuac") ? "True" : "False";
}