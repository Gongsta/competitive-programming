#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll h[n];
        for (int i=0;i<n;i++) {
            cin >> h[i];
        }
        /*
        If n even, you have to choose to start either at i=1 or i=2 to maximize
        If n odd, you start at i=1
        */
        ll cost = 0;
        if (n % 2 == 1) {
            for (int i=1;i<n;i+=2) {
                if (h[i] <= max(h[i-1], h[i+1])) {
                    cost += max(h[i-1], h[i+1]) - h[i] + 1;
                }
            }
            cout << cost << endl;
        } else {
            ll dp[n];
            dp[0] = 0;
            dp[n-1] = 0;
            ll suffix[n];
            ll prefix[n];
            prefix[0] = 0;
            for (int i=1;i<n-1;i++) {
                if (h[i] <= max(h[i-1], h[i+1])) {
                    dp[i] = max(h[i-1], h[i+1]) - h[i] + 1;
                } else {
                    dp[i] = 0;
                }
                if (i == 1) {
                    prefix[i] = dp[i];
                } else {
                    prefix[i] = dp[i] + prefix[i-2];
                }
            }
            suffix[n-1] = 0;
            for (int i=n-2;i>=0;i--) {
                if (i == n -2) {
                    suffix[i] = dp[i];

                } else {
                    suffix[i] = dp[i] + suffix[i+2];
                }
            }
            ll cost = suffix[1];
            for (int i=1;i<n-1;i+=2) {
                if (i == 1) {
                    cost = min(cost, suffix[i+1]);
                } else {
                    cost = min(prefix[i-2] + suffix[i+1], cost);
                }
            }
            cout << cost << endl;
            // for (auto x: prefix) {
            //     cout << x << endl;
            // } 
            // cout << "suffix" << endl;
            // for (auto x: suffix) {
            //     cout << x << endl;
            // } 


        }

    }

    return 0;
}
