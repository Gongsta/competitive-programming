#include <bits/stdc++.h>

using namespace std;

int dp[100001];
int h[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    for (int i=1;i<=N; i++) {
        cin >> h[i];
    }
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);
    for (int i=3;i<=N; i++) {
        int min_val = 1 << 30;
        for (int k=i-K; k<i; k++) {
            if (k > 0) {
                min_val = min(min_val, abs(h[i]-h[k]) + dp[k]);
            }
        }
        dp[i] = min_val;
    }
    cout << dp[N] << endl;

    return 0;
}
