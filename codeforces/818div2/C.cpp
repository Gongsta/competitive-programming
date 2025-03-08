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
        int b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        bool works = true;
        for (int i = 0; i < n; i++) {
            if (b[i] < a[i]) {
                works = false;
                break;
            }
        }

        int largest_a = *max_element(a, a + n);
        int smallest_b = *min_element(b, b + n);

        int curr_i = max_element(a, a + n) - a;

        // First, let's get a to match b where the value of b is the smallest
        if (smallest_b < largest_a) {
            for (int i = 0; i < n; i++) {
                a[curr_i] = max(a[curr_i], min(b[curr_i], a[(curr_i + 1) % n] + 1));
                curr_i--;
                curr_i = (curr_i + n) % n;
            }
        } else {
            // we can just get everythng to be value of b
            for (int i = 0; i < n; i++) {
                a[i] = smallest_b;
            }
        }

        // Update, starting from smallest b
        curr_i = min_element(b, b + n) - b;
        for (int i = 0; i < n; i++) {
            a[curr_i] = max(a[curr_i], min(b[curr_i], a[(curr_i + 1) % n] + 1));
            curr_i--;
            curr_i = (curr_i + n) % n;
        }

        // Check
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                works = false;
                break;
            }
        }

        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        /*
        1 2 3 4 5
        9 8 7 6 5
        14 13 12 11 10
        20 19 18 17 16

        */
    }

    return 0;
}
