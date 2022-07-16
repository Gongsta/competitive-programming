#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int H, N;
    cin >> H >> N;
    int heights[N];
    for (int i=0;i<N;i++) {
        cin >> heights[i];
    }
    ll dp[H+1];
    ll INF = 1 << 30;
    for (int i=0;i<=H;i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for (int i=1;i<=N;i++) {
        for (int h=H;h>=0;h--) {
            if (h - heights[i-1] >= 0) {
                dp[h] = min(dp[h], dp[h-heights[i-1]] + 1);
            }
        }
    }
    if (dp[H] < 1 << 30) {
        cout << dp[H] << endl;
    } else {
        cout << 0 << endl;
    }


    return 0;
}
