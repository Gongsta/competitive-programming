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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int d[m];
        int f[k];
        for (int i = 0; i < m; i++) {
            cin >> d[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> f[i];
        }
        sort(f, f + k);
        vector<pair<int, int>> diffs;
        for (int i = 1; i < n; i++) {
            diffs.push_back({a[i] - a[i - 1], i});
        }

        sort(diffs.begin(), diffs.end(), greater<pair<int, int>>());

        int lower = a[diffs[0].second - 1];
        int upper = a[diffs[0].second];
        int target = (lower + upper) / 2;
        int ans = diffs[0].first;
        for (int i = 0; i < m; i++) {
            auto it = lower_bound(f, f + k, target - d[i]);
            // If found value, else will point to closest greatera
            if (it != f + k) {
                int val = *it + d[i];
                ans = min(ans, max(val - lower, upper - val));
            }
            // Previous value
            if (it != f) {
                int val = *prev(it) + d[i];
                ans = min(ans, max(val - lower, upper - val));
            }
        }

        if (diffs.size() == 1) {
            cout << ans << endl;

        } else {
            cout << max(ans, diffs[1].first) << endl;
        }
        /*
        We want to find a number such that d_i + f_j is bounded by [lower, upper];
        */
    }

    return 0;
}
