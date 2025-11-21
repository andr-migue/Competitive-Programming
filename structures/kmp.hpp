#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const std::string &S)
{
    int n = (int)S.size();
    vector<int> pi(n);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];

        while (j > 0 && S[i] != S[j])
        {
            j = pi[j - 1];
        }

        if (S[i] == S[j])
        {
            j++;
        }

        pi[i] = j;
    }
    return pi;
}

int kmp(string pat, string txt)
{
    int ans = 0;
    int n = pat.size();

    vector<int> pi = prefix_function(pat + '$' + txt);

    for (int i = n + 1; i < pi.size(); i++)
    {
        if (pi[i] == n)
        {
            ans++;
        }
    }

    return ans;
}