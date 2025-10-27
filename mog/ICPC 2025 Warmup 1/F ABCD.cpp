#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> A(n), B(n), C(n), D(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    map<int, int> m1, m2;
    for (int a : A)
    {
        for (int b : B)
            m1[a + b]++;
    }

    for (int c : C)
    {
        for (int d : D)
            m2[-(c + d)]++;
    }

    int ans = 0;
    for (pair<int, int> p : m1)
    {
        ans += p.second * m2[p.first];
    }

    cout << ans;

    return 0;
}