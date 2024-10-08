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
            res = res % ll(1e9 + 7);
        }
        a = a * a;
        a = a % ll(1e9 + 7);
        b >>= 1;
    }
    return res;
}

ll sum_custom(ll a, ll b, ll base) {
    ll left = (base - 1ll) * (binpow(base, a) - 1ll) / (base - 1ll);
    ll right = (base - 1ll) * (binpow(base, b) - 1ll) / (base - 1ll);
    // cout << left << " " << right << endl;
    return (right - left + ll(1e9 + 7)) % ll(1e9 + 7);
}

/*

Hypothesis: The digits cannot carry over.

n >= 10^l

Say the number is 9, then we have two choices 0, or 1

2^l for all numbers < 10^{l+1}
Then, we have 2 ^(l+1), since the one in front is locked.

then for the next one, it's also 9 * 2^(l+1). Notice that we multiply by

0
1
00
10
01
11
2^0 + 2^ 1 + 2^2




*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll l, r, k;
        cin >> l >> r >> k;
        if (k >= 10) {
            cout << 0 << endl;
        } else if (k >= 5) {  // 2^n
            cout << sum_custom(l, r, 2) << endl;
        } else if (k == 4) {  // 3^n
            cout << sum_custom(l, r, 3) << endl;

        } else if (k == 3) {  // 4^n
            cout << sum_custom(l, r, 4) << endl;

        } else if (k == 2) {  // 5^n
            cout << sum_custom(l, r, 5) << endl;
        } else {  // 10^n
            cout << sum_custom(l, r, 10) << endl;
        }
    }

    return 0;
}
