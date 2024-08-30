#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max_s = accumulate(a, a + n, 0);
    int dp[n][max_s + 1];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int s = 0; s < max_s; s++) {
            if (i == 0) {
                if (s == 0) {
                    dp[i][s] = 1;
                } else {
                    dp[i][s] = 0;
                }
            }
            dp[i][s] += dp[i - 1][s];
            if (s >= a[i]) {
                dp[i][s] += dp[i - 1][s - a[i]];
            }
            cout << dp[i][s] << " ";
        }
        cout << endl;
    }
    // cout << dp[n-1][max_s] << endl;

    return 0;
}
