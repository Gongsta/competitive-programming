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

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;
/*
Goal: maximimize the number of bits where the b = xor of a and c's bits ,i.e. if a and c are 0, then we want b to be 1.

If 0,0 -> 1
if 1,1 -> 0
if 0,1 or 1,0 -> either 1 or 0 will maximize

So we simply need to find a b that satisfies these.

However, we want to maximize the sum. So we want the xor to make the largest possible number. That's why if both are 1s, we want b to be 0, so that the xor'ed number has a 1 bit.
But it won't matter if a and c are 1,0 or 0,1, the contribution to the sum will be the same.

What if we can't? Which do we eliminate?

I have an idea where you greedily do things and check if like the remaining is 0, would that still be smaller than c
and if the remaining is 1, would that be greater than a?

And sort of do it recursively.

Logic:
- Compare it bitwise. As long as there are ties, you use those numbers.
*/

// 14 114
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        int a = l;
        int b = r;
        int c = 0;
        int first_diff = -1;
        for (int i = 29; i >= 0; i--) {
            int bit = 1 << i;
            if ((a & bit) == (b & bit)) {
                c += (a & bit);
            } else {
                first_diff = i;
                break;
            }
        }
        int mask = 0;
        int avail = first_diff;
        for (int i = first_diff; i >= 0; i--) {
            int bit = 1 << i;
            if ((a & bit) == (b & bit)) {
                if ((a & bit) == 0) {
                    c += (mask & l);
                    c += bit;
                } else {
                    c += (mask & r);
                }
                avail = i - 1;
                break;
            } else {
                mask += bit;
            }
        }
        for (int i = avail; i >= 0; i--) {
            int bit = 1 << i;
            if ((a & bit) == (b & bit)) {
                c += ((a & bit) == 0) << i;
            } else {
                c += (b & bit);
            }
        }
        if (c == b) {
            c--;
        }

        cout << a << " " << b << " " << c << endl;
    }

    return 0;
}
