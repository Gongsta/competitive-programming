#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;

ll modinv(ll x, ll mod) {
    ll res = 1;
    ll power = mod - 2;
    while (power) {
        if (power % 2) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        power /= 2;
    }
    return res;
}

ll prefix_sum(vector<ll>& prefix, int l, int r) {
    if (l == 0) {
        return prefix[r];
    }
    return (prefix[r] - prefix[l - 1] + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                prefix[i] = a[i];
            } else {
                prefix[i] = (prefix[i - 1] + a[i]) % MOD;
            }
        }
        ll sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum = (sum + (a[i] * prefix_sum(prefix, i + 1, n - 1)) % MOD) % MOD;
        }
        ll num_pairs = (n * (n - 1) / 2ll) % MOD;

        ll num_pairs_inv = modinv(num_pairs, MOD);
        ll ans = (sum * num_pairs_inv) % MOD;
        cout << ans << endl;
    }

    return 0;
}
