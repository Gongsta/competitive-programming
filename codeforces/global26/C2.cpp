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

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a;
        }
        res %= 998244353ll;
        a = a * a;
        a %= 998244353ll;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll sum = 0;
        ll min_val = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum < min_val) {
                min_val = sum;
            }
        }
        sum = 0;
        ll ans = 0;
        ll tmp_ans = 1;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum >= 0) {
                tmp_ans *= 2ll;
                tmp_ans %= 998244353ll;
            }
            if (sum == min_val && sum < 0) {
                ans += (tmp_ans * binpow(2, n - i - 1)) % 998244353ll;
                ans %= 998244353ll;
                // cout << i << " " << ans << endl;
            }
        }
        if (ans == 0) {
            ans += tmp_ans;
            ans %= 998244353;
        }
        cout << ans << endl;
    }

    return 0;
}
