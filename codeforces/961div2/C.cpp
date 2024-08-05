#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
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
If always decreasing,
op[i] = op[i-1] + relative_ops(i-1, i)

We can calculate this cumutively.
- Also, op[i] >=0, so you need to take a max

however, we should always store negative numbers, in the case that a[i-1] << a[i]. I get it..

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
        bool works = true;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > 1 && a[i] == 1) {
                works = false;
                break;
            }
        }
        if (!works) {
            cout << -1 << endl;
        } else {
            ll dp[n];
            memset(dp, 0, sizeof(dp));
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    dp[i] = 0;
                } else {
                    ll relative_ops = 0;
                    ll him = a[i - 1];
                    ll me = a[i];
                    while (him < me && him != 1) {
                        him *= him;
                        if (him <= me) {
                            relative_ops--;
                        }
                    }
                    him = a[i - 1];
                    me = a[i];
                    while (me < him) {
                        me *= me;
                        relative_ops++;
                    }
                    dp[i] = max(dp[i - 1] + relative_ops, 0ll);
                }
            }
            ll ans = 0;
            for (int i = 0; i < n; i++) {
                ans += dp[i];
            }
            cout << ans << endl;
        }
    }

    return 0;
}
