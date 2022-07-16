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
        ll a[n];
        ll dp[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        dp[n-1] = a[n-1];
        ll max_score = a[n-1];
        for (int i=n-1;i>=0;i--) {
            if (a[i] + i < n) {
                dp[i] = a[i] + dp[i+a[i]];
            } else {
                dp[i] = a[i];
            }
            max_score = max(max_score, dp[i]);
        }
        cout << max_score << endl;

    }

    return 0;
}
