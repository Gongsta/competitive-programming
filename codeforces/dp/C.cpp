#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    ll dp[2][2][2];
    for (int i=0;i<2;i++) {
        for (int j=0;j<2;j++) {
            for (int k=0;k<2;k++) {
                dp[i][j][k] = 1 << 30;
            }
        }
    }
    while (n--)  {
        string s;
        ll c;
        cin >> c;
        cin >> s;
        int val = 0;
        int a=0,b=0,f=0;
        for (int i=0;i<s.length();i++) {
            if (s[i] == 'A') a = 1;
            if (s[i] == 'B') b = 1;
            if (s[i] == 'C') f = 1;
        }
        dp[a][b][f] = min(dp[a][b][f], c);
    }
    // This is terrible, but I thought this was quicker than doing a loop and having to worry 
    // about the logic
    dp[1][1][0] = min(dp[1][1][0], dp[1][0][0] + dp[0][1][0]);
    dp[0][1][1] = min(dp[0][1][1], dp[0][1][0] + dp[0][0][1]);
    dp[1][0][1] = min(dp[1][0][1], dp[1][0][0] + dp[0][0][1]);
    dp[1][1][1] = min(dp[1][1][1], dp[1][0][0] + dp[0][1][1]);
    dp[1][1][1] = min(dp[1][1][1], dp[0][1][0] + dp[1][0][1]);
    dp[1][1][1] = min(dp[1][1][1], dp[0][0][1] + dp[1][1][0]);
    dp[1][1][1] = min(dp[1][1][1], dp[0][1][1] + dp[1][1][0]);
    dp[1][1][1] = min(dp[1][1][1], dp[0][1][1] + dp[1][0][1]);
    dp[1][1][1] = min(dp[1][1][1], dp[1][1][0] + dp[1][0][1]);

    if (dp[1][1][1] >= 1 << 30) {
        cout << -1 << endl;
    } else {
        cout << dp[1][1][1] << endl;
    }

    return 0;
}
