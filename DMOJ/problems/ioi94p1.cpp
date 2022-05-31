#include <bits/stdc++.h>

using namespace std;

int dp[100][100];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0; j<=i;j++) {
            cin >> dp[i][j];
        }
    }
    
    for (int n=N-1;n>0; n--) {
        for (int i=0; i<n; i++) {
            dp[n-1][i] = max(dp[n-1][i] + dp[n][i], dp[n-1][i] + dp[n][i+1]);
        }
    }
    
    cout << dp[0][0] << endl;
    
    
    
    return 0;
}
