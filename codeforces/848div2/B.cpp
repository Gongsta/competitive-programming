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
        int n, m, d;
        cin >> n >> m >> d;
        int p[n];
        int a[m];
        map<int, int> mm;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            mm[p[i]] = i;
        }

        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        int ans = n - 1;
        for (int i = 0; i < m - 1; i++) {
            if (mm[a[i]] < mm[a[i + 1]] && mm[a[i + 1]] <= mm[a[i]] + d) {
                if (d < n - 1) {
                    ans = min(ans, min(mm[a[i + 1]] - mm[a[i]], mm[a[i]] + d - mm[a[i + 1]] + 1));
                } else {
                    ans = min(ans, mm[a[i + 1]] - mm[a[i]]);
                }
            } else {
                ans = 0;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
