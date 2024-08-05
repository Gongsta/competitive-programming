#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
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

typedef long long ll;

using namespace std;

/*
Make observation on when does g become 0. You can brute force and do it in O(n^2), count the number of times.

Use a prefix sum? How does that help?
- Solve using DP

Let dp[i] be the number of intervals that don't exceed the level
j be the first number that exceeds the level

dp[i] = dp[j]

*/

ll dp[200001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        ll a[n];
        ll prefix[n];
        ll dp[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            prefix[i] = a[i];
            if (i != 0) {
                prefix[i] += prefix[i - 1];
            }
            dp[i] = 0;
        }

        ll ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            int j = lower_bound(prefix + i, prefix + n, x + prefix[i] - a[i] + 1) - prefix;
            if (j >= n - 1) {
                dp[i] = j - i;

            } else {
                dp[i] = dp[j + 1] + (j - i);
            }
            ans += dp[i];
        }
        cout << ans << endl;
    }

    return 0;
}
