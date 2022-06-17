#include <bits/stdc++.h>

using namespace std;

int dp[100000];

/*
I was close, but I did not think of the optimal strategy...
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    dp[0]= 0;
    dp[1] = 0;
    dp[2] = 2;
    dp[3] = 6;
    for (int i=4;i<100000;i++) {
        if (i % 3 == 1) {
            dp[i] = 2 * i/3 + dp[i-1];

        } else if (i % 3 == 2) {
            dp[i] = 2 * i/3 + dp[i-1];
        } else {
            if ((i / 3) % 2 == 1) {
                dp[i] = 4 * 2 * (i/3 - 1) + dp[i-1];
            } else {
                dp[i] = 4 * 2 * i/3 + dp[i-1];
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0;i<100000;i++) {
            if (dp[i] >= n) {
                cout << i << endl;
                break;
            }
        }

    }

    return 0;
}
