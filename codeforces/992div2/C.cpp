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
        int n, k;
        cin >> n >> k;
        vector<int> v;
        if (n <= 40 && k > (1ll << (n - 1))) {
            cout << -1 << endl;
        } else {
            k--;
            vector<int> left;
            vector<int> right;
            vector<int> d;
            while (k > 0) {
                d.push_back(k & 1);
                k = k >> 1;
            }

            while (d.size() < n - 1) {
                d.push_back(0);
            }
            reverse(d.begin(), d.end());
            for (int i = 1; i <= n - 1; i++) {
                // cout << i << " " << d[i - 1] << endl;
                if (d[i - 1] % 2 == 0) {
                    left.push_back(i);
                } else {
                    right.push_back(i);
                }
            }
            reverse(right.begin(), right.end());
            for (auto x : left) {
                cout << x << " ";
            }
            cout << n << " ";
            for (auto x : right) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
