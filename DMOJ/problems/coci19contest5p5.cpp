#include <bits/stdc++.h>

using namespace std;

dp[351];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    return 0;
    

    /*
    valid = # ways to distribute - # invalid positions
    dp[0] = 0 
    dp[1] = 1
    dp[2] = 2 * (1,1) + 1* (0,2) + 1* (2,0) -> 0
    dp[3] = (0,1,2) + (0,0,3) + (0,)
    so we fix the first position()
    
    if we get to be the desired amount
    say you fix (1, ..) how many possible good positions?
    (1,1) -> 2!
    (1,1,1) -> 3! + (1,0,2) 2 + (1,2,0) -> oh wait double counting!
    (1,1,1,1) -> 4!
    
    */
   for (int i=2;i<=N;i++) {

   }
   cout << dp[N] << endl;
    
}
