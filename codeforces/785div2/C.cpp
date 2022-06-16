#include <bits/stdc++.h>

using namespace std;

int reverse(int n)
{
    int r=0;
    while(n>0)
    {
        r=r*10+n%10;
        n/=10;
    }
    return r;
}
int is_palindrome(int x) {
    return x == reverse(x);
    
}

int dp[400001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    vector<int> palindromes;
    for (int i=1; i<=40000;i++) {
        if (is_palindrome(i)) {
            palindromes.push_back(i);
        }
    }
    dp[0] = 1;
    dp[1] = 1;
    for (int i=2;i<=40000;i++) {
        dp[i] = dp[i-1];
        for (auto pal: palindromes) {
            if (pal > i) {
                break;
            }
            dp[i] += dp[i-pal] % 1000000007; // The problem is that I am double counting
        }
    }

    while (t--) {
        int n;
        cin >> n;

        
        cout << dp[n] << endl;


    }

    return 0;
}
