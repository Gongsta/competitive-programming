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
        // intuition: you can always just take all but 1 set, and check
        int n;
        cin >> n;
        set<int> v[n];
        int ans = 0;
        set<int> total_set;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                v[i].insert(x);
                total_set.insert(x);
            }
        }
        for (auto x : total_set) {
            set<int> local;
            for (int i = 0; i < n; i++) {
                if (v[i].count(x)) {
                    continue;
                }
                for (auto y : v[i]) {
                    local.insert(y);
                }
            }
            if (local.size() < total_set.size()) {
                ans = max(ans, (int)local.size());
            }
        }
        cout << ans << endl;
    }

    return 0;
}
