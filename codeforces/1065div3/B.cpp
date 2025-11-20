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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (i == 0 || i == n - 1) {
                    continue;
                } else {
                    a[i] = 0;
                }
            }
        }
        int sum_diffs = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] == -1 || a[i - 1] == -1) {
                continue;
            }
            sum_diffs += a[i] - a[i - 1];
        }

        if (a[n - 1] == -1) {
            if (a[0] == -1) {
                a[0] = 0;
                if (n > 2) {
                    sum_diffs += a[1] - a[0];
                }
            }
            a[n - 1] = a[n - 2] - sum_diffs;
            sum_diffs = 0;
        }
        if (a[0] == -1) {
            a[0] = sum_diffs + a[1];
            sum_diffs += a[1] - a[0];
        }
        cout << abs(sum_diffs) << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
