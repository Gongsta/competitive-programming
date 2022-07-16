#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,T;
    cin >> N >> T;
    int hours[N];
    int v[N];
    for (int i=0;i<N;i++) {
        cin >> v[i];
        cin >> hours[i];
    }
    int dp[N+1][T+1];
    for (int i=0;i<=N;i++) {
        for (int h=0;h<=T;h++) {
            if (i == 0 || h == 0) {
                dp[i][h] = 0;
            } else {
                if (h - hours[i-1] >= 0) {
                    dp[i][h] = max(dp[i-1][h], dp[i-1][h-hours[i-1]] + v[i-1]);
                } else {
                    dp[i][h]= dp[i-1][h];
                }
            }
        }
    }
    cout << dp[N][T] << endl;

    return 0;
}
