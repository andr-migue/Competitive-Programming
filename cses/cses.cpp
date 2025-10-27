#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int diez = n / 100;
    int zerosTen = diez * (diez + 1) / 2;
    int five = (n / 5) - diez*10 + zerosTen;
    cout << five;
}