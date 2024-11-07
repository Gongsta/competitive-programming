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

#define int long long  // Because i'm so done with integer overflow mistakes
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, q;
        cin >> n >> q;
        ll x[n];
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        unordered_map<ll, ll> m;
        ll cum_sum = 0;
        for (ll i = 1; i < n; i++) {
            m[i * (n - i)] += x[i] - x[i - 1] - 1;
            m[i * (n - i) + (i - 1)] += 1;
        }
        m[n - 1] += 1;  // for last number

        while (q--) {
            ll k;
            cin >> k;
            cout << m[k] << " ";
        }
        cout << endl;
    }

    return 0;
}
