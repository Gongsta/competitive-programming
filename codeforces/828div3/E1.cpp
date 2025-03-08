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
Idea: Do a prime factorization
example:
12 21 14 24

2*2*3, 3*7

So the two numbers together must be at least 2*2*3*3*7.

k(a * b) = c * d
d = k (a*b)/ c;

Compute the LCM?

we want k (a*b) >= x * d
k >= x * d / a*b;
*/

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool found = false;
    for (int x = a + 1; x <= c; x++) {
        int y = lcm(x, a * b) / x;
        int val = b + 1 + ((y - ((b + 1) % y)) % y);
        if (val <= d) {
            cout << x << " " << val << endl;
            return;
        }
    }

    // not found
    cout << "-1 -1" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
