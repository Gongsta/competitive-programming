#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    ll mod = 1e9+7;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll ans = 0;
        ll G = 1;
        for (ll i=1;G<=n;i++) {
            G = lcm(G, i);
            if (G > n) break;
            ans += n/G;
        }
        cout << (ans + n) % mod << endl;

    }

    return 0;
}
