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
    First day, total number of combinations is:
    s0 * (total number of trails) + l0 * (sum of short trails)

    Following days, we need to accumulate the weights of the possiblities.
    - How many times can we end up in cabin 1 again?
    s0 * (s0 + l0) + l0 * s0

    number of ways to end up in s1 after 1 day:
    s0 * (s1 + l1) + l0 * s1

    More generally, we have sum:
    ways to end on i (after taking short trail) = (# ways to end on each cabin j * s_j) * (s_i + l_i)
    + (# ways to end on each cabin j * l_j) * (s_i)

    This is O(nm^2), we need n iterations, and for each cabin, we need o iterate over the m cabins
    but we can just precompute this sum.
    */
    int m, n;
    cin >> m >> n;
    int s[m];
    int l[m];
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> l[i];
    }
    int MOD = 1e9 + 7;
    vector<int> cabins(m, 0);
    cabins[0] = 1;
    for (int i = 0; i < n; i++) {
        int s_sum = 0;
        int l_sum = 0;
        for (int j = 0; j < m; j++) {
            s_sum += (cabins[j] * s[j]) % MOD;
            l_sum += (cabins[j] * l[j]) % MOD;
            s_sum %= MOD;
            l_sum %= MOD;
        }
        for (int j = 0; j < m; j++) {
            cabins[j] = (s_sum % MOD) * (s[j] + l[j]) % MOD + (l_sum % MOD) * (s[j]) % MOD;
            ;
            cabins[j] %= MOD;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans += cabins[i];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
