#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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
10 -> 2 away
11 -> 1 away from setting to 0

*/

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int l = n;
        int r = 1152921504606846977ll;
        int ans = r;
        // check if that bit has not been flipped between n and mid
        /*
        10 = 0b1010

        8 = 0b1000

        0 -> 0 -> anything is 0, so any number is ok
        0 -> 1 -> impossible
        1 -> 1 -> the number has an upper bound of the range
        1 -> 0 -> number has a lower bound of range

        And then you basically need to find an overlapping range that satisfies
        all constraints.
        */
        for (int b = 0; b < 63; b++) {
            int bit = 1ll << b;
            int bitmask = bit - 1ll;
            if ((n & bit) == 0 && (x & bit) > 0) {
                ans = -1;
                break;
            } else if ((n & bit) == 0) {
                // can be any number in the bounds
                continue;
            } else if ((n & bit) > 0 && (x & bit) > 0) {
                r = min(r, n | bitmask);
            } else {  // 0 and 1
                l = max(l, (n & ~bitmask) + bit);
            }
        }
        if (l > r) {
            ans = -1;
        } else if (ans != -1) {
            ans = l;
        }
        cout << ans << endl;
    }

    return 0;
}
