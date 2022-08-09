#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


ll dp[2000][2000];
ll s[2000];

ll solve(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return dp[l][r] = 0;
    return dp[l][r] = s[r] - s[l] + min(solve(l+1, r), solve(l, r-1));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> s[i];
    }
    sort(s, s+n);
    memset(dp, -1, sizeof(dp));
    solve(0, n-1);
    cout << dp[0][n-1] << endl;


    return 0;
}
