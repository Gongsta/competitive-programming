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

using namespace std;

// Practicing an alternative implementation using 2 pointers

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]]++;
        }
        vector<pair<int, int>> v;
        for (auto &x : m) {
            v.push_back({x.first, x.second});
        }
        int l = 0;
        int r = 0;
        int curr_sum = v[l].second;
        int ans = 0;
        while (l < v.size()) {
            // Get value
            ans = max(ans, curr_sum);

            // Move pointer
            if (r + 1 >= v.size() || (r - l == k - 1)) {
                curr_sum -= v[l].second;
                l++;
            } else if (v[r + 1].first == v[r].first + 1) {
                r++;
                curr_sum += v[r].second;
            } else {  // missmatch, cannot use l
                r++;
                l = r;
                curr_sum = v[l].second;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
