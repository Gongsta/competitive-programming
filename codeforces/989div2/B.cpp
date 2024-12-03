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
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        int curr = 0;
        int ans = 0;
        int i = 0;
        while (i < n) {
            char c = s[i];
            if (c == '0') {
                curr++;
            } else {
                curr = 0;
            }
            if (curr == m) {
                ans++;
                curr = 0;
                i += k - 1;
            }
            i++;
        }
        cout << ans << endl;
    }

    return 0;
}
