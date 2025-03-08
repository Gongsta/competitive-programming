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
#include <vector>
// #include <unordered_map> // NEVER USE THOSE IN CP
// #include <unordered_set> // NEVER USE THOSE IN CP

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

/*
If you saw one of the numbers already, then you must use the other number.

And add that to the set of visited.
Impossible to have seen obth numbers, since it has to be a valid permutation.

So when you have 2 numers that you can pick from, how do you do it? Search right?

*/
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int MOD = 1e9 + 7;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int b[n];
        int c[n];
        map<int, int> next_a;
        map<int, int> next_b;
        bool visited[n];
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            next_a[a[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            next_b[b[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (visited[i] || a[i] == b[i]) {
                continue;
            }
            visited[i] = true;

            int curr_idx = next_b[a[i]];
            bool is_fixed = (c[i] != 0);

            while (curr_idx != i) {
                visited[curr_idx] = true;
                if (c[curr_idx] != 0) {
                    is_fixed = true;
                }
                curr_idx = next_b[a[curr_idx]];
            }

            if (!is_fixed) {
                ans *= 2ll;
                ans %= MOD;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
