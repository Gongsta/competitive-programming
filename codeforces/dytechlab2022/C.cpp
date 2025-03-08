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
        // Any of the horizontals can be reached from the l shape +- 2
        // Any of the vertical can be reached from the l shape +- 2
        int n;
        cin >> n;
        int r1, c1, r2, c2, r3, c3;
        cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
        vector<int> rs = {r1, r2, r3};
        vector<int> cs = {c1, c2, c3};
        sort(rs.begin(), rs.end());
        sort(cs.begin(), cs.end());
        int r, c;
        if (rs[0] == rs[1]) {
            r = rs[0];
        } else {
            r = rs[2];
        }
        if (cs[0] == cs[1]) {
            c = cs[0];
        } else {
            c = cs[2];
        }
        int x, y;
        cin >> x >> y;
        // Check corner case
        if ((c == 1 || c == n) && (r == 1 || r == n)) {
            if (y == c || x == r) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            if (abs(r - x) % 2 == 0 || abs(c - y) % 2 == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
