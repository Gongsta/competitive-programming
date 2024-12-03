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
        set<int> s;
        int ans = 0;
        int cumsum = 0;
        for (int i = 0; i < n; i++) {
            cumsum += a[i];
            if (s.count(cumsum) || cumsum == 0) {
                ans++;
                s.clear();
                cumsum = 0;
            } else {
                s.insert(cumsum);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
