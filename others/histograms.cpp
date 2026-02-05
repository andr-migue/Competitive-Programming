#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mid(l, r) ((l + r) / 2)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())

typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;

vector<int> prefix_function(const vector<int> &s)
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

int kmp(const vector<int> &pat, const vector<int> &txt)
{
    int n = pat.size();

    vector<int> combined;

    for (int x : pat)
        combined.push_back(x);

    combined.push_back(LLONG_MIN);

    for (int x : txt)
        combined.push_back(x);

    vector<int> pi = prefix_function(combined);

    int count = 0;

    for (int i = n + 1; i < (int)pi.size(); i++)
    {
        if (pi[i] == n)
            count++;
    }

    return count;
}

signed main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<int> difA;

    for (int i = 1; i < n; i++)
    {
        difA.push_back(a[i] - a[i - 1]);
    }

    vector<int> difB;

    for (int i = 1; i < m; i++)
    {
        difB.push_back(b[i] - b[i - 1]);
    }

    cout << kmp(difB, difA) << endl;
}