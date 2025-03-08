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
        int n, k, d;
        cin >> n >> k >> d;
        int a[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int v[k];
        for (int i = 0; i < k; i++) {
            cin >> v[i];
        }
        int ans = 0;
        // base case
        for (int i = 1; i <= n; i++) {
            if (a[i] == i) {
                ans++;
            }
        }
        ans += (d - 1) / 2;  // remaining days, greedily add and take

        int curr = 0;
        for (int i = 1; i <= min(2 * n, d - 1); i++) {
            int end = v[curr];
            int total = 0;
            for (int j = 1; j <= n; j++) {
                if (j <= end) {
                    a[j] += 1;
                }
                if (a[j] == j) {
                    total++;
                }
            }
            ans = max(ans, total + (d - i - 1) / 2);
            curr++;
            curr %= k;
        }
        cout << ans << endl;
    }

    return 0;
}
