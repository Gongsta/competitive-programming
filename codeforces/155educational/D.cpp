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

int prefix_xor(int l, int r, vector<int>& prefix) {
    if (l == 0) {
        return prefix[r];
    }
    return prefix[r] ^ prefix[l - 1];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll MOD = 998244353;
    int n;
    cin >> n;
    int a[n];
    vector<int> prefix(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int b = 0; b < 30; b++) {
        ll cb = 1 << b;

        vector<ll> cnt(2, 0);
        vector<ll> sum(2, 0);
        cnt[0] = 1;
        for (ll i = 0; i < n; i++) {
            int a_i = (a[i] & cb) >> b;
            if (i == 0) {
                prefix[i] = a_i;
            } else {
                prefix[i] = a_i ^ prefix[i - 1];
            }
            // cout << prefix[i] << endl;
            sum[prefix[i]] += i + 1;
            cnt[prefix[i]]++;
            ll cv = (cnt[prefix[i] ^ 1] * (i + 1ll) - sum[prefix[i] ^ 1]);
            cv %= MOD;
            ans += cb * cv;
            ans %= MOD;
        }
    }
    cout << ans << endl;

    return 0;
}
