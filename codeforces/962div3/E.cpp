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
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;

using namespace std;

ll prefix_sum(int l, int r, vector<ll>& prefix) {
    if (l == 0) {
        return prefix[r];
    }
    return prefix[r] - prefix[l - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll n = s.length();
        ll prefix[n + 1];
        prefix[0] = 0;
        for (ll i = 1; i <= n; i++) {
            ll num = -1;
            if (s[i - 1] == '1') {
                num = 1;
            }
            prefix[i] = num + prefix[i - 1];
        }
        map<ll, ll> m;
        ll ans = 0;
        ll MOD = 1e9 + 7;
        for (ll i = 0; i <= n; i++) {
            ans = (ans + m[prefix[i]] * (n - i + 1ll)) % MOD;
            m[prefix[i]] = (m[prefix[i]] + i + 1) % MOD;
        }
        cout << ans << endl;
    }

    return 0;
}
