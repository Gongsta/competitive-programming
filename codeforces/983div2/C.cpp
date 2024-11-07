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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

/*
Worst case is n -1, every number gets assigned to the same number

*/

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
        sort(a, a + n);
        int ans = n - 1;
        for (int i = 1; i < n; i++) {
            auto it = lower_bound(a + i, a + n, a[i] + a[i - 1]);
            if (it == a + i) {
                continue;
            }
            int left = i - 1;
            int right = a + n - it;
            ans = min(ans, left + right);
        }

        cout << ans << endl;
    }

    return 0;
}
