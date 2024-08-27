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

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int r, c;
        vector<bool> rows(n, false);
        for (int i = 0; i < k; i++) {
            cin >> r >> c;
            r--;
            c--;
            rows[r] = true;
            rows[c] = true;
        }
        int free = 0;
        for (int i = 0; i < n; i++) {
            if (!rows[i]) {
                free++;
            }
        }
        ll dp[free + 1];
        dp[0] = 1;
        dp[1] = 1;
        ll MOD = 1e9 + 7;
        for (ll i = 2; i <= free; i++) {
            dp[i] = (dp[i - 1] + 2ll * (i - 1) * dp[i - 2] % MOD) % MOD;
        }
        cout << dp[free] << endl;
    }

    return 0;
}
