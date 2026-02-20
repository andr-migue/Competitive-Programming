#include <iostream>

using namespace std;

long long pow(long long a, long long b) {
    if (b == 0)
        return 1;

    if (b & 1)
        return (a * pow(a, b - 1)) % 1000000007;
    else
        return pow(a * a, b / 2) % 1000000007;
}

long long calc_inv(long long a) {
    return pow(a, 1000000007 - 2);
}

int main() {
    long long fact[251];
    fact[0] = 1;
    for (int i = 1; i < 250; i++)
        fact[i] = (i * fact[i - 1]) % 1000000007;

    long long inv[251];
    inv[0] = 1;
    for (int i = 1; i < 250; i++)
        inv[i] = calc_inv(i * inv[i - 1]);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, k;
        cin >> n >> k;

        long long ans = 0;
        // ans = fact[n + k - 1] / (fact[k - 1] * fact[n]);
        ans = fact[n + k - 1] * inv[k - 1] * inv[n];

        //if (k > n) {
        //    ans = 0;
        //} else {
        //    ans = fact[n + k - 1] / (fact[k - 1] * fact[n]);
        //    // ans = fact[n + k - 1] * inv[k - 1] * inv[n];
        //}

        cout << ans << "\n";
    }

    return 0;
}