#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;

using namespace std;

ll factorial[200001];
ll MOD = 1e9 + 7;

ll inv(ll a) {
    return a <= 1 ? a : MOD - (long long)(MOD / a) * inv(MOD % a) % MOD;
}

ll C(ll n, ll k) {
    if (n < k) return 0;
    if (n == 0) return 1;
    return factorial[n] * inv(factorial[k] * factorial[n - k] % MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    factorial[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        int x = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                x++;
            }
        }
        ll ans = 0;
        for (int i = k / 2 + 1; i <= k; i++) {
            ans += (C(x, i) * C(n - x, k - i)) % MOD;
            ans %= MOD;
        }
        cout << ans << endl;
    }

    return 0;
}
