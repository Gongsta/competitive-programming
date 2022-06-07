#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int dp[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    dp[0] = arr[0];
    for (int i=1;i<N;i++) {
        if (i-3 >=0) {
            dp[i] = max(dp[i-2], dp[i-3]) + arr[i];
        } else if (i-2 >= 0) {
            dp[i] =dp[i-2] + arr[i];
        } else {
            dp[i] = arr[i];
        }
    }

    if (N >= 2) {
        cout << max(dp[N-1], dp[N-2]) << endl;
    } else {
        cout << dp[N-1] << endl;

    }
    

    return 0;
}
