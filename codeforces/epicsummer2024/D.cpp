#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
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
/*
Alice will eat the smallest, bob will eat the greatest cake. why doesn't this greedy solution work?

1 3 3 4 5

non optimal
1
3
5

optimal
1 3

So bob needs to use his brain. Alice should always pick the smallest number??
- Yes, because if she picks the bigger number, Alice can't eat the smaller number anymore. yea, so it doesn't make a difference. If bob eats the bigger number,
Alice can still eat the smaller number. And so she can always consume from the biggest set of numbers by eating the smallest number.

dp[n][n]

If alice turn,
dp[i] = max(dp[i+1])
*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    dp[i][j] = 

                }
            }
        }

        return 0;
    }
