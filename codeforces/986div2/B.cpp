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
        int n, b, c;
        cin >> n >> b >> c;
        if (n == 1) {
            if (c == 0) {
                cout << 0 << endl;
            } else {
                cout << 1 << endl;
            }
        } else if (n == 2) {
            if (c == 0 && b == 1) {
                cout << 0 << endl;
            } else if (c == 0 || c == 1) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        } else {
            if (b == 0 && c <= n - 3) {
                cout << -1 << endl;
            } else if (c >= n) {
                cout << n << endl;
            } else {
                int mid;
                if (b == 0) {
                    mid = 0;
                } else {
                    mid = (n - 1 - c) / b;
                }
                int ans = n - 1 - mid;
                cout << ans << endl;
            }
        }
    }

    return 0;
}
