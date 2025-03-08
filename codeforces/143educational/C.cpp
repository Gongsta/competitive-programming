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
    /*
    This idea of windows and points can definitely work, I need to figure it out

    */

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        vector<int> b(n);
        vector<int> b_pref(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        b_pref[0] = b[0];
        for (int i = 1; i < n; i++) {
            b_pref[i] = b_pref[i - 1] + b[i];
        }

        vector<int> cnts(n, 1);
        vector<int> subs(n, 0);
        for (int i = 0; i < n; i++) {
            int prefix = 0;
            if (i > 0) {
                prefix = b_pref[i - 1];
            }
            auto it = lower_bound(b_pref.begin() + i, b_pref.end(), a[i] + prefix);
            int j = (it - b_pref.begin());
            if (j >= n) {  // If everyone can drink it, nothing else to do
                continue;
            }
            if (j + 1 < n) {
                cnts[j + 1]--;
            }
            int consumed = b_pref[j] - prefix;  // Always non-negative by the binary search setup
            subs[j] += consumed - a[i];
        }

        int curr_total = 0;
        for (int i = 0; i < n; i++) {
            curr_total += cnts[i];
            cout << curr_total * b[i] - subs[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
