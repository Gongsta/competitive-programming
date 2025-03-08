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
9, 10-> 9, 1
19, 20 -> 10, 2,
29, 30, 11, 3
39, 40, 12, 4
99, 100, 18, 1
109, 110-> 10, 2
119, 120 -> 11, 3
999, 1000 -> 27, 1
9999, 10000 -> 36, 1
4959, 4960 -> 27, 19
1999, 2000 -> 28, 2

x + 9 + CONST -> x + 1 + CONST

11 1
999 1000
9999 1000

2999, 3000 -> 29, 3

x + k * 9 + CONST -> x + 1 + CONST
decrease from k*9 -> 1


If 1, must be multiple



1199, 1200 -> 20, 3

*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if ((y == x + 1) || (x > y && (x - y + 1) % 9 == 0 && y >= 1)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
