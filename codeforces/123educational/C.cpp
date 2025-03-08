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
    /*
    -3 -3 4 4 4
    for x = 4, k = 2
    my solution gives 14

    but it should be 20
    can you do the sum at the end? But if they're all negative, you get an incorrect answer :(

    Like you can't just add k*x, because it's contingent on the subarray being of length >= k.

    So you compute the length of this subarray sum (original form). for all k <= to its length, that is the answer.
    - For k > than its length, you need to consider that other numbers can now increase?

    k = 3 -> answer is the 4 4 4 subarray
    x = 100
    3 3 3 1 -INF 5 5 5

    dp[n][k]
    dp[i][0] = dp[i] -> the classic formulation for maximum subarray sum
    dp[i][j] = max(dp[i-1][j-1] + x + a[i], dp[i-1][j] + x];

    Nope nope, you just do O(n^2)

    */

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int dp[n];
        int INF = 1e9;
        for (int i = 0; i < n; i++) {
            dp[i] = -INF;
        }

        for (int i = 0; i < n; i++) {
            int curr_sum = 0;
            for (int j = i; j < n; j++) {
                curr_sum += a[j];
                dp[j - i] = max(dp[j - i], curr_sum);
            }
        }
        for (int k = 0; k <= n; k++) {
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans = max(ans, dp[i] + min(k, i + 1) * x);
            }
            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}
