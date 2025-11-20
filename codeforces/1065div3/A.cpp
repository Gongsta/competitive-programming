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
/*
Lower bound # of elements -> upper bound is 2^n - 1

Reasoning about sizes
If multiset of size 1, # of elements that have the same max size
If multiset of size 2, you can brute force it
If multiset of size 3,
*/

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            if (n - 2 * i < 0) {
                continue;
            }
            if ((n - 2 * i) % 4 == 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
