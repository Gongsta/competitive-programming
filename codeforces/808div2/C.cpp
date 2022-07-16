#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,Q;
        cin >> n >> Q;
        if (Q > 100001) {
            Q = 100001;
        }
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        int dp[Q+1];
        memset(dp, 0, sizeof(dp));
        string parents[Q+1];
        for (int i=1;i<=n;i++) {
            bool used = false;
            for (int q=Q;q>0;q--) {
                if (a[i-1] > q) {
                    if (dp[q-1] + a[i-1] > dp[q]) {
                        dp[q] = dp[q-1] + a[i-1];
                        parents[q] += '1';
                    } else {
                        parents[q] += '0';
                    }
                } else {
                    dp[q] += a[i-1];
                    parents[q] += '1';
                }
            }
        }
        // So I think I got the right answer, but I didn't know how to do the parent pointers
        // string final;
        // int curr_Q = Q;
        // for (int i=n;i>0;i--) {
        //     final += parents[curr_Q][i-1];
        //     if (parents[curr_Q][i-1] == '1') {
        //         if (a[i-1] > curr_Q) {
        //             curr_Q--;
        //         }
        //     }
        // }
        // reverse(final.begin(), final.end());
        // cout << final << endl;
        for (int i=0;i<=Q;i++) {
            cout << i << endl;
            cout << dp[i] << endl;
            cout << parents[i] << endl;
// 
        }

    }

    return 0;
}
