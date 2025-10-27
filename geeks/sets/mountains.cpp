#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> A)
{
    int n = A.size();

    vector<int> left(n);
    vector<int> right(n);

    multiset<int> leftSet;
    multiset<int> rightSet;

    for (int i = 0; i < n; i++)
    {
        left[i] = distance(leftSet.begin(), leftSet.lower_bound(A[i])); // left[i] = leftSet.Rank(A[i]);
        leftSet.insert(A[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        right[i] = distance(rightSet.begin(), rightSet.lower_bound(A[i])); // right[i] = rightSet.Rank(A[i]);
        rightSet.insert(A[i]);
    }

    int ans = 0;

    for (int i = 1; i < n - 1; i++)
    {
        ans += left[i] * right[i];
    }

    return ans;
}

signed main()
{
    vector<int> A = {1, 3, 2, 4, 1, 10, 100000, 2, 2, 2, 600, 1, 1, 4 , 14, 5};

    cout << solve(A);
}