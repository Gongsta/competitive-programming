#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll dp[1001][1001];
ll suffix[1001][1001];

ll dec(int n, int k, int start) {
    if (n == 0) return 0;
    if (k == 1) return 1;
    if (dp[k][start] != -1) return dp[k][start];
    ll total = 1; // This initial one
    for (int i=start;i<n;i++) {
        total += dec(n,k-1,n-i);
    }
        total %= 1000000007;
    return dp[k][start] = total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,kk;
        memset(dp, -1, sizeof(dp));
        memset(suffix, -1, sizeof(suffix));
        cin >> n >> kk;
        for (int k=1;k<=kk;k++) {
            if (k > 1) {
                for (int i=2;i<=n;i++) {
                    dp[k-1][i] += dp[k-1][i-1];
                    dp[k-1][i] %= 1000000007;
                }
            }
            for (int start=0;start<=n;start++) {
                if (k == 1) {
                    dp[k][start] = 1;
                } else {
                    dp[k][start] = 1;
                    // for (int i=start;i<n;i++) {
                    dp[k][start] += dp[k-1][n-start];
                        // dp[k][start] += suffix_sum(k-1, n-start);
                    // }
                    dp[k][start] %= 1000000007;
                }
            }
        }
        cout << dp[kk][0] << endl;

    }

    return 0;
}
