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

int power_of_two(int m) {
    for (int i = 0; i < 31; i++) {
        if ((1 << i) == m) {
            return i;
        }
    }
    return -1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*
    - m must be a power of 2 (unless n is a multiple of m)
    */

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int g = gcd(n, m);
        if (__builtin_popcount(m / g) > 1) {
            cout << -1 << endl;
        } else {
            int ans = 0;
            while (n > 0) {
                n %= m;
                ans += n;
                n *= 2;
            }
            cout << ans << endl;
        }
    }

    return 0;
}
