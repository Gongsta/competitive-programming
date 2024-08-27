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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        unordered_set<ll> s[n];
        for (int i = 0; i < n; i++) {
            int l;
            cin >> l;
            for (int j = 0; j < l; j++) {
                ll x;
                cin >> x;
                s[i].insert(x);
            }
        }
        vector<ll> p[n];
        ll max_mex = 0;
        for (int i = 0; i < n; i++) {
            for (ll x = 0; x <= 2e5 + 1; x++) {
                if (p[i].size() == 2) {
                    break;
                }
                if (!s[i].count(x)) {
                    if (p[i].size() == 1) {
                        max_mex = max(max_mex, x);
                    }
                    p[i].push_back(x);
                }
            }
        }
        // sort(p, p + n);
        ll ans = max_mex * min(max_mex + 1, m + 1);
        // cout << "before" << ans << endl;
        ans += max(m * (m + 1) / 2ll - max_mex * (max_mex + 1) / 2ll, 0ll);
        // for (int x = 0; x <= m; x++) {
        //     int val = x;
        //     for (int i = 0; i < n; i++) {
        //         if (val == p[i][0]) {
        //             val = p[i][1];
        //         }
        //     }
        //     cout << x << " " << val << endl;
        //     ans += max(max_mex, val);
        // }
        cout << ans << endl;
    }

    return 0;
}
