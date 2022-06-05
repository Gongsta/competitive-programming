#include <bits/stdc++.h>

using namespace std;

long long int dp[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    for (int i=2;i<=N;i++) { // i is the weight of the node
        long long int sub_tree_combinations = 0;
        for (int k=2; k<=i;k++) { // k represents the number of subtrees
            int max_w = i/k;
            sub_tree_combinations += dp[max_w];
        }
        dp[i] = sub_tree_combinations;
    }
    cout << dp[N] << endl;
    return 0;
}
