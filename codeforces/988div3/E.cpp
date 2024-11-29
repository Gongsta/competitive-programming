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
        int n;
        cin >> n;
        cout << "? 1 2" << endl;
        int f;
        cin >> f;
        string ans;
        int l = 1;
        int r = 3;

        if (f == 1) {
            ans += "01";
        }
        while (f == 0 && r <= n) {
            cout << "? " << l << " " << r << endl;
            cin >> f;
            if (f == 0) {
                r++;
            } else {  // equal to 1, the string is 111...0001
                int num_zeros = f;
                int num_ones = r - l - num_zeros;
                for (int i = 0; i < num_ones; i++) {
                    ans += '1';
                }
                for (int i = 0; i < num_zeros; i++) {
                    ans += '0';
                }
                ans += '1';
                l = r - 1;
                r++;
            }
        }

        while (r <= n) {
            cout << "? " << l << " " << r << endl;
            cin >> f;
            if (f == r - l) {
                ans += "1";
                r++;
            } else {
                ans += "0";
                l = r;
                r++;
            }
        }

        if (ans.empty()) {
            cout << "! IMPOSSIBLE" << endl;
        } else {
            cout << "! " << ans << endl;
        }
    }

    return 0;
}
