#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 1000000;
    set<ll> primes;
    vector<bool> is_prime(n+1, true);
    int nookokjjk
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.insert(i*i);
            if ((long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        if (primes.count(x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        // It is T-prime if sqrt of this number is a prime


    }

    return 0;
}
