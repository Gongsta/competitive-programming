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

    int n, m;
    cin >> n >> m;
    int r[n + 1];
    vector<int> i_checks[m + 1];
    vector<int> s_checks[m + 1];
    int curr = 0;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
        if (r[i] == 0) {
            curr++;
        } else if (r[i] > 0) {
            i_checks[curr].push_back(r[i]);
        } else {
            s_checks[curr].push_back(-r[i]);
        }
    }
    for (int i = 1; i <= m; i++) {
        sort(i_checks[i].begin(), i_checks[i].end());
        sort(s_checks[i].begin(), s_checks[i].end());
        // cout << i << " " << i_checks[i].size() << endl;
        // cout << i << " " << s_checks[i].size() << endl;
    }

    int dp[m + 1];  // m represents the strength attribute score at the i-th index
    int INF = 2e7;
    for (int i = 0; i <= m; i++) {
        dp[i] = -INF;
    }
    dp[0] = 0;

    int ans = 0;
    for (int total = 1; total <= m; total++) {
        // Do the updates
        for (int S = total; S >= 0; S--) {
            int P = total - S;
            auto itS = upper_bound(s_checks[total].begin(), s_checks[total].end(), S);
            auto itP = upper_bound(i_checks[total].begin(), i_checks[total].end(), P);
            int s_val = max((long long)(itS - s_checks[total].begin()), 0ll);
            int i_val = max((long long)(itP - i_checks[total].begin()), 0ll);

            // take the s
            if (S > 0) {
                dp[S] = max(dp[S - 1] + s_val + i_val, dp[S] + s_val + i_val);
            } else {
                dp[S] += s_val + i_val;
            }
            // cout << total << " " << S << " " << s_val << " " << i_val << " " << dp[S] << endl;
            // cout << total << " " << S << " " << dp[S] << endl;
            ans = max(ans, dp[S]);
        }
    }
    cout << ans << endl;

    return 0;
}
