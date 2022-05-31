#include <bits/stdc++.h>

using namespace std;

int dp[26][26];
bool cats[26][26];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    /* Top left is (1,1)
    dp[i][j] = dp[i-1][j] + dp[i][j-1]
    
    */
    int R,C;
    cin >> R >> C;
    
    int K;
    cin >> K;
    int r,c;
    while (K--) {
        cin >> r >> c;
        cats[r][c] = true;
    }
    dp[1][1] = 1;
    for (int i=1;i<=R; i++) {
        for (int j=1;j<=C; j++) {
            if (i-1 >= 0) {
                if (!cats[i-1][j]) {
                    dp[i][j] += dp[i-1][j];
                }
            }
            if (j-1 >= 0) {
                if (!cats[i][j-1]) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
    }
    
    cout << dp[R][C] << endl;

    return 0;
}
