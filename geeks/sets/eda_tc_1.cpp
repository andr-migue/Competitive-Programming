#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> A, int n, int l, int r)
{
    int ans = 0;
    multiset<int> ms;

    for (int i = 0; i < n; i++)
    {
        ans += distance(ms.begin(), ms.lower_bound(A[i] - l)); // ans += ms.Rank(A[i] - l);
        ms.insert(-A[i] - r);
    }

    return ans;
}

signed main()
{
    vector<int> A = {1, 8};

    cout << solve(A, A.size(), 2, 10);
}