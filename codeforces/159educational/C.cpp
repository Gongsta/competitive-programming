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
    // Take the GCD of the distances
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        if (n == 1) {
            cout << 1 << endl;
        } else {
            int dist = a[1] - a[0];
            for (int i = 2; i < n; i++) {
                dist = gcd(dist, a[i] - a[i - 1]);
            }
            int end = a[n - 1] - dist;
            for (int i = n - 1; i >= 0; i--) {
                if (a[i] == end) {
                    end -= dist;
                }
            }

            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans += (a[n - 1] - a[i]) / dist;
            }
            ans += (a[n - 1] - end) / dist;
            cout << ans << endl;
        }
    }

    return 0;
}
