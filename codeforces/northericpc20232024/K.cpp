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
    int n;
    cin >> n;
    int a[n];
    int dp[n][4];
    int MOD = 998244353;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= 2;
    }
    /*
    number of subsequences where the last two are those numbers...

    0 -> 00
    1 -> 01
    2 -> 10
    3 -> 11

    10000001

    0010
    1110

    101
    011
    1011

    or
    101

    110

    110

    1010


    How to set up base cases? You only need to check the first times that these subsequences appear
    000
    101
    110
    011
    */
    vector<int> q[4];
    q[0] = {0, 0, 0};
    q[1] = {1, 0, 1};
    q[2] = {0, 1, 1};
    q[3] = {1, 1, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (!q[j].empty() && a[i] == q[j].back()) {
                q[j].pop_back();
                if (q[j].empty()) {
                    dp[i][j] = 1;
                }
            }
        }
        if (i < 2) {
            continue;
        }

        for (int j = 0; j < 4; j++) {
            dp[i][j] += dp[i - 1][j];
            int x = j & 2;
            int y = j & 1;
            if (a[i] == y) {
                dp[i][j] += dp[i - 1][j];  // for last element, you can choose between y or a[i]
            }
            if ((x + y + a[i]) % 2 == 0) {
                int k = (y << 1) + a[i];
                dp[i][k] += dp[i - 1][j];
            }
            // Account for ways that we can choose this number instead of the previous number,
            // not changing length of subsequence

            if (j == 0) {
                cout << i << " " << dp[i][j] << endl;
            }
        }
    }
    cout << accumulate(dp[n - 1], dp[n - 1] + 4, 0) << endl;

    return 0;
}
