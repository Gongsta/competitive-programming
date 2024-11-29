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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        map<int, int> m;
        int n, k;
        cin >> n >> k;
        int c;
        for (int i = 0; i < n; i++) {
            cin >> c;
            m[c]++;
        }
        vector<pair<int, int>> v;
        for (auto x : m) {
            v.push_back({x.second, x.first});
        }

        sort(v.begin(), v.end());

        int excess = 0;
        int ans = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i].first + excess >= k) {
                excess += v[i].first - 1;
            } else {
                ans += v[i].first;
            }
        }
        cout << ans + min(excess, k - 1) << endl;
    }

    return 0;
}
