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
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int pre_xor = 0;
        int ans = 0;
        bool xors[(1 << 8)];
        memset(xors, 0, sizeof(xors));
        xors[0] = true;

        for (int i = 0; i < n; i++) {
            pre_xor ^= a[i];
            xors[pre_xor] = true;
            for (int i = 0; i < (1 << 8); i++) {
                if (xors[i]) {
                    ans = max(ans, i ^ pre_xor);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
