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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        // greedily take a-b as their value, to figure out which one is more worth it
        // That doesn't work.
        // So make an exception for the one that has the largest sum.
        /*
        My confusion is: why doesn't greedy work?
        Why can't we predetermine the optimal column, take the one that has the largest combined sum??

        Because consider this example:
        2  10
        19 10

        You cannot just guarantee that you have optimal.
        */
        int n;
        cin >> n;
        int a[2][n];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        vector<pair<int, pair<int, int>>> v;
        int ans = -1e9;
        for (int largest_sum_i = 0; largest_sum_i < n; largest_sum_i++) {
            int curr = a[0][largest_sum_i] + a[1][largest_sum_i];
            for (int j = 0; j < n; j++) {
                if (j != largest_sum_i) {
                    curr += max(a[0][j], a[1][j]);
                }
            }
            ans = max(ans, curr);
        }
        cout << ans << endl;
    }

    return 0;
}
