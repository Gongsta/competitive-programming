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

// go bit by bit, if a_i | a_j = 0, then both must be zero. If that is violated, then it's bad.
// - If there's a 1, one of the two can be a zero, but one of them must be a 1. So put it as a zero.

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int M[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        int a[n];
        memset(a, 0, sizeof(a));

        bool works = true;
        for (int k = 0; k < 30; k++) {
            int bit = 1 << k;
            for (int i = 0; i < n; i++) {
                bool has_zero = false;
                for (int j = 0; j < n; j++) {
                    if (j == i) {
                        continue;
                    }
                    if ((bit & M[i][j]) == 0) {
                        has_zero = true;
                    }
                }
                if (!has_zero) {
                    a[i] += bit;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if ((a[i] | a[j]) != M[i][j]) {
                    works = false;
                }
            }
        }
        if (works) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
