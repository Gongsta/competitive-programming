#include <bits/stdc++.h>

using namespace std;

/*
Observations:
If k >= n, then the damage is 0
If k = 0, then the damage is just the sum
Else

*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        int arr[n];
        int damage = 0;
        int dp[n]; // not really dp but just naming it for the sake. Represents the difference between current damage and minimum damage you can take
        for (int i=0;i<n;i++) {
            cin >> arr[i];
            damage += arr[i];
            if (arr[i] > n - i - 1) {
                dp[i] =(n-i - 1); // The minimum

            } else {
                dp[i] = arr[i];
            }
            dp[i] = arr[i] - dp[i];
        }
        sort(dp,dp+n,greater<int>()); // This doesn't work, since you are jumping between traps in order. 
        // So the jumping is biased?
        

        for (int i=0;i<k;i++) {
            damage -= (dp[i]);
            if (i != 0 && dp[i] != 0) {
                damage -= 1;
            }
        }
        cout << damage << endl;
    }

    return 0;
}
