#include <iostream>

using namespace std;
int main() {
    int N,W;
    cin >> N >> W;
    long long wt[N+1];
    long long v[N+1];
    for (int i=1;i<=N;i++) {
        cin >> wt[i] >> v[i];
    }
    long long dp[N+1][W+1];
    for (int i=0;i<=N;i++) {
        for (int w=0;w<=W;w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else {
                if (wt[i] > w) {
                    dp[i][w] = dp[i-1][w];
                } else {
                    dp[i][w] = max(dp[i-1][w], v[i] + dp[i-1][w - wt[i]]);
                }
            }
        }
    }
    cout << dp[N][W] << endl;
}
