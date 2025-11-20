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

int n;
int a[(int)2e5];
int b[(int)2e5];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int bit = 31; bit >= 0; bit--) {
        int b_mask = 1ll << bit;
        int num_diff = 0;
        int last_i = -1;
        for (int i = 0; i < n; i++) {
            if ((a[i] & b_mask) != (b[i] & b_mask)) {
                num_diff++;
                last_i = i;
            }
        }
        if (num_diff % 2 == 0) {
            continue;
        }
        if (last_i % 2 == 0) {
            cout << "Ajisai" << endl;
        } else {
            cout << "Mai" << endl;
        }
        return;
    }
    cout << "Tie" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
        /*
        Look at the ones where a_i == b_i, that is our start xor (both players start the same).
        since changing doesn't do anything.
        Then, for the ones that do change (0 or 1).
        Winner is determined when it's the last to act.
        */
    }

    return 0;
}
