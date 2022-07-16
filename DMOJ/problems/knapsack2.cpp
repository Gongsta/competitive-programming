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
    ll dp[W+1];
    for (int i=0;i<N;i++) {
        cin >> wt[i];
        cin >> v[i];
    }
    memset(dp, 0, sizeof(dp));
    for (ll i=1;i<=N;i++) {
        for (ll w=W;w>=0;w--) {
            if (w - wt[i-1] >= 0) {
                dp[w] = max(dp[w], dp[w-wt[i-1]] + v[i-1]);
            }
        }
    }
    cout << dp[W] << endl;

    return 0;
}
