#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> A, int n, int l, int r)
{
    int ans = 0;
    multiset<int> ms;

    for (int i = 0; i < n; i++)
    {
        ans += distance(ms.begin(), ms.lower_bound(A[i] - l + 1)); // ans += ms.Rank(A[i] - l + 1);
        ms.insert(-A[i] - r);
    }

    return ans;
}

signed main()
{
    vector<int> A = {1, 8, 5, 6, 7, 7,7,7 ,9};

    cout << solve(A, A.size(), 2, 10);
}