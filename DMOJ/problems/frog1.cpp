#include <bits/stdc++.h>

using namespace std;

int dp[100001];
int h[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i=1;i<=N; i++) {
        cin >> h[i];
    }
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);
    for (int i=3;i<=N; i++) {
        dp[i] = min(abs(h[i]-h[i-1]) + dp[i-1], abs(h[i]-h[i-2]) + dp[i-2]);
    }
    cout << dp[N] << endl;

    return 0;
}
