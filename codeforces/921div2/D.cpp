#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
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
#include <vector>
// #include <unordered_map> // NEVER USE THOSE IN CP
// #include <unordered_set> // NEVER USE THOSE IN CP

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

int MOD = 1e9 + 7;

const int MAXN = 1e5 + 1;
int factorial[MAXN];

int inv(int a) {
    return a <= 1 ? a : MOD - (int)(MOD / a) * inv(MOD % a) % MOD;
}

int choose(int n, int k) {
    return factorial[n] * inv(factorial[k] * factorial[n - k] % MOD) % MOD;
}

int modpow(int x, int n, int m) {
    if (n == 0) {
        return 1 % m;
    }
    long long u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) {
        u = (u * x) % m;
    }
    return u;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (m == 0) {
            cout << 0 << endl;
            continue;
        }
        int a[m];
        int b[m];
        int f[m];
        for (int i = 0; i < m; i++) {
            cin >> a[i] >> b[i] >> f[i];
        }

        if (n == 2) {
            // Do the sum
            int ans = 0;
            for (int i = 0; i < k; i++) {
                ans += f[0];
                ans %= MOD;
                f[0]++;
            }
            cout << ans << endl;
        } else {
            int numerator = 0;
            int factor = modpow(choose(n, 2), k, MOD);
            int factor2 = 0;
            for (int j = 0; j < k; j++) {
                factor2 += ((j * modpow(choose(n, 2), k - 1, MOD)) % MOD);
                factor2 %= MOD;
            }
            for (int i = 0; i < m; i++) {
                numerator += (((f[i] * factor) % MOD) * k) % MOD;
                numerator %= MOD;
            }
            numerator += (m * factor2) % MOD;
            numerator %= MOD;
            int denom = modpow(choose(n, 2), k + 1, MOD);
            cout << (numerator * inv(denom)) % MOD << endl;
        }
    }

    return 0;
}
