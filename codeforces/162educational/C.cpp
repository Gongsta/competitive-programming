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

int prefix(vector<int>& ones, int l, int r) {
    if (l == 0) {
        return ones[r];
    }
    return ones[r] - ones[l - 1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int c[n];
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        vector<int> ones(n, 0);
        vector<int> to_decrease(n, 0);

        if (c[0] == 1) {
            ones[0] = 1;
        } else {
            ones[0] = 0;
        }
        to_decrease[0] = c[0] - 1;

        for (int i = 1; i < n; i++) {
            if (c[i] == 1) {
                ones[i] = 1 + ones[i - 1];
            } else {
                ones[i] = ones[i - 1];
            }
            to_decrease[i] = to_decrease[i - 1] + c[i] - 1;
        }

        // Just check the number of ones, if they are > (r - l + 1) / 2, then impossible
        /*
        subarray of 3 -> max one 1
        subarray of 4 -> max two 1
        subarray of 5 -> max 2 1
        */
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int ones_to_decrease = prefix(ones, l, r);
            int available_decrease = prefix(to_decrease, l, r);
            if (ones_to_decrease > available_decrease || l == r) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}
