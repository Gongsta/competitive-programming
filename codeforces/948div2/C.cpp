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

/*

A subsequence will contain its LCM if the prime factors of the number >= max(prime exponent) for all numbers

1 can be excluded for a length of subsquence without 1 is >= 2
LCM is given by max of the prime exponents multiplied together.


*/

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            n /= d;
            factorization.push_back(n);
        }
    }
    if (n > 1) {
        factorization.push_back(n);
    }
    return factorization;
}

void solve() {
    int n;
    cin >> n;
    ll a[n];
    unordered_set<ll> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    ll max_num = 0;
    ll lcm_num = 1;
    for (int i = 0; i < n; i++) {
        max_num = max(a[i], max_num);
    }
    for (int i = 0; i < n; i++) {
        lcm_num = lcm(a[i], lcm_num);
        if (lcm_num > max_num) {
            cout << n << endl;
            return;
        }
    }

    int ans = 0;
    for (ll factor = 1; factor * factor <= max_num; factor++) {
        if (max_num % factor != 0 || s.count(factor)) {
            continue;
        }
        int local_ans = 0;
        int lcm_num = 1;
        for (int i = 0; i < n; i++) {
            if (factor > a[i] && factor % a[i] == 0) {
                lcm_num = lcm(lcm_num, a[i]);
                local_ans++;
            }
        }
        if (lcm_num == factor) {  // correct lcm at the end
            ans = max(ans, local_ans);
        }
    }

    for (ll factor_2 = 1; factor_2 * factor_2 <= max_num; factor_2++) {
        if (max_num % factor_2 != 0 || s.count(max_num / factor_2)) {
            continue;
        }
        ll factor = max_num / factor_2;
        int local_ans = 0;
        int lcm_num = 1;
        for (int i = 0; i < n; i++) {
            if (factor > a[i] && factor % a[i] == 0) {
                lcm_num = lcm(lcm_num, a[i]);
                local_ans++;
            }
        }
        if (lcm_num == factor) {  // correct lcm at the end
            ans = max(ans, local_ans);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
