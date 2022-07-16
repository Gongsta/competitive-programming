#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


ll mod = 1e9+7;

ll power(ll n, ll pow) {
    ll final = 1;
    for (ll i=0;i<pow;i++) {
        final = ((final % mod) * (n % mod)) % mod;
    }
    return final;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n,k;
        cin >> n >> k;
        ll start = 1;
        ll total = 0;
        ll shift = 0;
        while ((k >> shift) > 0) {
            if (k & (1 << shift)) {
                total += power(n, shift) % mod;
                total %= mod;
            }
            shift++;
        }
        cout << total << endl;
    }

    return 0;
}
