#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    set<int> seen;
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {
        if (seen.count(a[i]) == 0)
        {
            seen.insert(a[i]);
            ans.push_back(a[i]);
        }
    }

    cout << ans.size() << endl;

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    
}