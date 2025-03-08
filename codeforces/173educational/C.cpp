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
        // 10 1 1 1 1 1
        /*
        Mark the special number as the pivot
        Sums before can be accumulated into a set, reset the counter to that number only with a change of signs.

        We can also do the same after.
        // 0 is always possible
        */
        int pivot = -1;
        set<int> left;
        set<int> right;
        set<int> pivot_set;

        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (abs(a[i]) != 1) {
                pivot = i;
            }
        }
        left.insert(0);
        right.insert(0);

        // traverse left
        int curr_sum = 0;
        int highest = 0;
        int lowest = 0;
        for (int i = 0; i < pivot; i++) {
            highest += a[i];
            lowest += a[i];
            highest = max(highest, 0ll);
            lowest = min(lowest, 0ll);
            left.insert(highest);
            left.insert(lowest);
        }
        // traverse right
        highest = 0;
        lowest = 0;
        for (int i = pivot + 1; i < n; i++) {
            highest += a[i];
            lowest += a[i];
            highest = max(highest, 0ll);
            lowest = min(lowest, 0ll);
            right.insert(highest);
            right.insert(lowest);
        }

        // traverse left from pivot
        curr_sum = 0;
        for (int i = pivot; i >= 0; i--) {
            curr_sum += a[i];
            pivot_set.insert(curr_sum);
        }

        if (pivot_set.size() != 0) {
            // traverse right and get the values
            curr_sum = 0;
            int smallest = *pivot_set.begin();
            int largest = *pivot_set.rbegin();
            for (int i = pivot + 1; i < n; i++) {
                curr_sum += a[i];
                if (curr_sum > 0) {
                    pivot_set.insert(curr_sum + largest);
                } else {
                    pivot_set.insert(curr_sum + smallest);
                }
            }
        }

        // merge the set values
        set<int> merged;
        for (auto x : left) {
            merged.insert(x);
        }
        for (auto x : right) {
            merged.insert(x);
        }
        for (auto x : pivot_set) {
            merged.insert(x);
        }

        cout << merged.size() << endl;
        for (auto x : merged) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
