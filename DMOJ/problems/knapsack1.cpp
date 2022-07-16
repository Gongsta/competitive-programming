#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll N,W;
    cin >> N >> W;
    ll wt[N];
    ll v[N];
    for (int i=0;i<N;i++) {
        cin >> wt[i];
        cin >> v[i];
    }
    ll dp[N+1][W+1];
    memset(dp,0, sizeof(dp));
    for (int i=0;i<=N;i++) {
        for (ll w=0;w<=W;w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (w - wt[i-1] >= 0) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i-1]] + v[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    cout << dp[N][W] << endl;

    return 0;
}
