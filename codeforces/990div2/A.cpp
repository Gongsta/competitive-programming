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

    set<int> is_clean;
    int curr = 1;
    for (int i = 1; i <= 10000; i += 2) {
        is_clean.insert(curr);
        curr += 2 * (2 * i + 2);
    }

    int t;
    cin >> t;
    while (t--) {
        // 1, 9 (3 + 3 + 1 + 1), (5 + 5 + 3 + 3)  + 9
        int n;
        cin >> n;
        int a[n];
        int total = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
            if (is_clean.count(total)) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
