#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,k,p;
    cin >> n >> k >> p;
    ll a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    ll b[k];
    for (int i=0;i<k;i++) {
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+k);
    
    ll dp[k+1][n+1];
    for (int i=0;i<=k;i++) {
        for (int j=0;j<=n;j++) {
            dp[i][j] = 1e17;
        }
    }
    dp[0][0] = 0;
    for (int i=0;i<k;i++) {
        for (int j=0;j<=n;j++) {
            // Don't take key, move onto the next key
            dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
            
            // Take Key
            if (j < n) {
                dp[i+1][j+1] = min(dp[i+1][j+1], max(dp[i][j], abs(a[j] - b[i]) + abs(p - b[i])));
            }
        }
    }
    cout << dp[k][n] << endl;

    return 0;
}
