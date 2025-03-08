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
        // you need to buy at most 2 intervals. You might be spared, but that's edge case
        int left;
        int c_left;
        int right;
        int c_right;
        pair<int, int> max_interval;
        int max_interval_c;
        for (int i = 0; i < n; i++) {
            int l, r, c;
            cin >> l >> r >> c;
            if (i == 0) {
                left = l;
                c_left = c;
                right = r;
                c_right = c;
                max_interval = {l, r};
                max_interval_c = c;
                cout << c << endl;
            } else {
                if (l == left && r == right) {
                    if (max_interval.first != l || max_interval.second != r) {
                        max_interval_c = c;
                    } else {
                        max_interval_c = min(max_interval_c, c);
                    }
                    max_interval = {l, r};
                } else if (l <= left && r >= right) {  // grew the range
                    max_interval = {l, r};
                    max_interval_c = c;
                }

                if (l == left) {
                    c_left = min(c_left, c);
                } else if (l < left) {
                    left = l;
                    c_left = c;
                }

                if (r == right) {
                    c_right = min(c_right, c);
                } else if (r > right) {
                    right = r;
                    c_right = c;
                }

                if (max_interval.first == left && max_interval.second == right) {  // the interval holds both limits
                    cout << min(c_left + c_right, max_interval_c) << endl;
                } else {
                    cout << c_left + c_right << endl;
                }
            }
        }
    }

    return 0;
}
