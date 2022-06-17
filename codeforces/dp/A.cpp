#include <bits/stdc++.h>

using namespace std;

int dp[51];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;
    if (n % 2 == 0) {
        cout << (1 << n/2) << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}
