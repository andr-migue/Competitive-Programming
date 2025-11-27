#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int k, n;
    cin >> k >> n;

    vector<int> a(k);
    vector<int> b(n);

    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    
    vector<int> sum(k + 1);
    
    for (int i = 0; i < k; i++)
    {
        sum[i + 1] = sum[i] + a[i];
    }
    
    set<int> xs;

    for (int i = 1; i <= k; i++)
    {
        xs.insert(b[0] - sum[i]);
    }
    
    int ans = 0;
    
    for (int x : xs)
    {
        set<int> bj;

        for (int i = 1; i < k + 1; i++)
        {
            bj.insert(x + sum[i]);
        }

        bool flag = true;

        for (int bi : b)
        {
            if (bj.find(bi) == bj.end())
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            ans++;
        }
    }

    cout << ans << endl;
}