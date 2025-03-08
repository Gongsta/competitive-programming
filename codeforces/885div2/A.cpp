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

signed main() {
    /*
    Off by 1 doesn't really matter, they will never be in sync/ Must be off by 2 in both x and y differences.

    */
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int x, y;
        cin >> x >> y;
        bool same = false;
        int cnt = 0;
        while (k--) {
            int i, j;
            cin >> i >> j;
            if (i == x && j == y) {
                same = true;
            }
            if ((abs(x - i) + abs(y - j)) % 2 == 0) {
                cnt++;
            }
        }
        if (same || cnt >= 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
