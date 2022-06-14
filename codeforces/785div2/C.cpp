#include <bits/stdc++.h>

using namespace std;

int is_palindrome(int x) {
    string s = to_string(x);
    string rev = s;
    reverse(s.begin(), s.end());
    return rev == s;
}
int dp[40000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        dp[0] = 0;
        dp[1] = 1;
        for (int i=2;i<=n;i++) {
            for (int j=1;j<i/2;j++) {
                dp[i] += dp[j];
                dp[i] += dp[i-j];
            }
            dp[i] += is_palindrome(i);
        }
        
        cout << dp[n] << endl;


    }

    return 0;
}
