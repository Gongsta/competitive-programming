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

// Store the farthest contiguous value
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

        for (int i = 0; i < v.size(); i++) {
            if (i != 0) {
                v[i].second += v[i - 1].second;
            }
        }

        int curr_consec = 0;
        int ans = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (i != v.size() - 1 && v[i].first + 1 == v[i + 1].first) {
                curr_consec++;
            } else {
                curr_consec = 0;
            }
            int curr_sum = 0;
            if (i == 0) {
                curr_sum = v[i + min(curr_consec, k - 1)].second;
            } else {
                curr_sum = v[i + min(curr_consec, k - 1)].second - v[i - 1].second;
            }
            ans = max(ans, curr_sum);
        }

        cout << ans << endl;
    }

    return 0;
}
