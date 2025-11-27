#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mid(l, r) ((l + r) / 2)
#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())

class dsu
{
public:
    vector<int> parent;

    dsu(int n)
    {
        parent.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int set_of(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = set_of(parent[x]);
        }
        return parent[x];
    }

    void fill(int x)
    {
        parent[x] = x + 1;
    }
};

signed main()
{
    int n;
    cin >> n;

    vector<int> capacities(n + 2);

    for (int i = 1; i <= n; i++)
    {
        cin >> capacities[i];
    }

    int m, q, v, c;
    cin >> m;

    vector<int> current(n + 2, 0);

    dsu dsu(n + 2);

    while (m--)
    {
        cin >> q;

        if (q == 1)
        {
            cin >> v >> c;

            while (c > 0)
            {
                int vessel = dsu.set_of(v);

                if (vessel > n) break;

                if (current[vessel] + c <= capacities[vessel])
                {
                    current[vessel] += c;
                    c = 0;
                }
                else
                {
                    int space = capacities[vessel] - current[vessel];
                    current[vessel] = capacities[vessel];
                    c -= space;
                    dsu.fill(vessel);
                }

                v = vessel + 1;
            }
            
        }
        else
        {
            cin >> v;
            cout << current[v] << endl;
        }
    }
}