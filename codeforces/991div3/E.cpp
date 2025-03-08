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
    int INF = 1e9;
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.size();
        int m = b.size();
        int l = c.size();
        int dp[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                int idx = i + j;
                if (i < n) {
                    int cost = dp[i][j] + (a[i] != c[idx]);
                    dp[i + 1][j] = min(cost, dp[i + 1][j]);
                }
                if (j < m) {
                    int cost = dp[i][j] + (b[j] != c[idx]);
                    dp[i][j + 1] = min(cost, dp[i][j + 1]);
                }
            }
        }
        cout << dp[n][m] << endl;
    }

    return 0;
}
