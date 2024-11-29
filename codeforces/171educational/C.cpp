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

/*
Draw as many edges as possible, edges exist from 1 to 1 or 1 to 0
If there is an edge going to 1 then cannot use that edge again


Strategy:
1. greedily associate 1 with the closest zero before it. If matchable, then you only need to pay for the 0 fee.
Wait but this doesn't work even in the trivial case 00001. You will choose to pay for the 4th zero when you
could've paid for the 1st zero. But its ok, You need to pay for the 4th zero anyways. So it doesn't matter. You can
never get the 4th for free. I mean you could if you do 1st and 4th, but you would never do that, just get the 5th.

2. Add to answer all zeros not marked

2. For all remaining 1s that are not matched, do a greedy strategy


*/

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<int> zeros;
        stack<int> ones;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zeros.push(i);
            } else {
                ones.push(i);
            }
        }

        // Step 1: Greedily associate one with the previous 0
        int ans = 0;
        while (!ones.empty()) {
            int x = ones.top();
            while (!zeros.empty() && zeros.top() > x) {
                ans += zeros.top() + 1;
                zeros.pop();
            }
            if (zeros.empty()) {
                break;
            }
            ans += zeros.top() + 1;  // take the zero before the one, and we get the one for free
            zeros.pop();
            ones.pop();
        }

        // Step 2: Count the remaining zeros, those must be paid for
        while (!zeros.empty()) {
            ans += zeros.top() + 1;
            zeros.pop();
        }

        vector<int> unmatched_ones;
        // Step 3: All remaining ones are unmatched, please match them from left to right
        while (!ones.empty()) {
            unmatched_ones.push_back(ones.top());
            ones.pop();
        }
        sort(unmatched_ones.begin(), unmatched_ones.end());
        int l = 0;
        int r = (int)unmatched_ones.size() - 1;
        while (l <= r) {
            ans += unmatched_ones[l] + 1;
            l++;
            r--;
        }

        cout << ans << endl;
    }

    return 0;
}
