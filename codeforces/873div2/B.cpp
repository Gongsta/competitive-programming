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
        int n;
        cin >> n;
        int p[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (p[i] != i) {
                if (ans == -1) {
                    ans = abs(p[i] - i);
                } else {
                    ans = gcd(ans, abs(p[i] - i));
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
