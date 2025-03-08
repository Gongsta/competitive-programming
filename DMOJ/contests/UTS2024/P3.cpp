#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
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
optimal solution makes each 1 a 0, so its the number of 1s.

Find groups of 1 bits

First, use your K greedily to make the even groups odd.

Then, if you have excess K, ans -= K , and ans=max(0, ans)

If you don't have excess K, you can

Consider
011011
You have 2 even groups.
Assume k = 0.

for even, the best is even_size + 2

No, adjacent evens work??
Adjacent evens can work together so it's 2 * even_size + 2


But you need to figure out when it's not possible?
When two evens, consider merging.

When does it not work? When everything is 1 and it's even, because you have no more bits to flip.

even+ odd- > make the odd zeros, then you have plenty of space

If you have an extra K. You should actually consider combining two evens? Flip 0 to 1?
the two has a + 4
use a single flip to make it -2. So does same thing.

But you should greedily prioritze those that can't make the leap

*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }

    vector<pair<int, int>> evens;
    vector<pair<int, int>> odds;

    int l = 0;
    while (l < n) {
        if (a[l] == 0) {
            l++;
            continue;
        }
        int r = l;
        while (r + 1 < n && a[r + 1] == 1) {
            r++;
        }
        if ((r - l + 1) % 2 == 0) {
            evens.push_back({l, r});
        } else {
            odds.push_back({l, r});
        }
        l = r + 1;
    }

    for (int i = 0; i < evens.size(); i++) {
        if (k <= 0) {
            break;
        }
        if ((evens[i].second - evens[i].first + 1) % 2 == 0) {  // make it odd
            evens[i].second--;
            k--;
        }
    }

    int ans = 0;
    for (auto& odd : odds) {
        ans += odd.second - odd.first + 1;
    }

    bool has_spacing = false;
    for (int i = 0; i < evens.size(); i++) {
        int len = evens[i].second - evens[i].first + 1;
        if (len % 2 == 1) {  // odd
            ans += len;
            has_spacing = true;
        } else {  // even, need to flip a 1 bit
            ans += len + 2;
            // check spacing requirements: before and after
            if (len > 2) {
                has_spacing = true;
            }
            if (i == 0) {
                if (evens[i].first != 0) {
                    has_spacing = true;
                }
            }
            if (i == evens.size() - 1) {
                if (evens[i].second != n - 1) {
                    has_spacing = true;
                }
            } else {
                if (evens[i].second + 1 < evens[i + 1].first - 1) {
                    has_spacing = true;
                }
            }
        }
    }
    // you have excess k that can be used to flip the remaining numbers. If you have excess, it means that all evens are odd now
    ans -= k;
    ans = max(ans, 0ll);

    if (evens.size() != 0 && !has_spacing) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
