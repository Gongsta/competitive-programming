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
        int q;
        cin >> q;
        vector<int> s_m(26, 0);
        vector<int> t_m(26, 0);
        s_m[0] = 1;
        t_m[0] = 1;
        while (q--) {
            int d, k;
            string x;
            cin >> d >> k >> x;
            if (d == 1) {
                for (char c : x) {
                    s_m[c - 'a'] += k;
                }
            } else {
                for (char c : x) {
                    t_m[c - 'a'] += k;
                }
            }
            bool smaller = false;
            for (int i = 1; i < 26; i++) {
                if (t_m[i] > 0) {
                    smaller = true;
                }
            }

            // Here, check for when t is completely full of a's, then s must also only be a's and shorterI
            int total_s_length = 0;
            for (int i = 0; i < 26; i++) {
                total_s_length += s_m[i];
            }
            if (total_s_length < t_m[0] && s_m[0] == total_s_length) {
                smaller = true;
            }

            if (smaller) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
