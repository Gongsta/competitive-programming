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
        int n;
        cin >> n;
        int a[n];
        int dp[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            dp[i] = a[i];
        }
        int ans = a[0];
        if (n > 1) {
            ans = max(ans, a[1]);
        }
        for (int i = 2; i < n; i++) {
            dp[i] = max(max(dp[i - 2], dp[i - 2] + a[i]), a[i]);
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
