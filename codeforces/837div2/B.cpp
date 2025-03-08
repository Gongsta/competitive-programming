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
        int n, m;
        cin >> n >> m;
        map<int, int> mm;
        for (int i = 1; i <= n; i++) {
            mm[i] = n;
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            if (x > y) {
                swap(x, y);
            }
            mm[x] = min(mm[x], y - 1);
        }
        int ans = 0;
        int last_val = n;
        for (auto iter = mm.rbegin(); iter != mm.rend(); ++iter) {
            last_val = min(iter->second, last_val);
            ans += last_val - iter->first + 1;
        }
        cout << ans << endl;
    }

    return 0;
}
