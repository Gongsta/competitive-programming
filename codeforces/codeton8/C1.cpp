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
        int n, x, y;
        cin >> n >> x >> y;
        int a[x];
        for (int i = 0; i < x; i++) {
            cin >> a[i];
        }
        sort(a, a + x);
        int ans = x - 2;
        for (int i = 1; i < x; i++) {
            if (a[i] - a[i - 1] == 2) {
                ans++;
            }
        }
        if (a[0] + n - a[x - 1] == 2) {
            ans++;
        }
        ans = min(ans, n - 2);
        cout << ans << endl;
    }

    return 0;
}
