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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int, int> b;
        for (int i = 0; i < m; i++) {
            int val;
            cin >> val;
            b[val]++;
        }
        map<int, int> a_map;
        for (int i = 0; i < m; i++) {
            a_map[a[i]]++;
        }
        int overlaps = 0;
        for (auto x : a_map) {
            overlaps += min(x.second, b[x.first]);
        }
        int ans = 0;
        if (overlaps >= k) {
            ans++;
        }

        // Count the number of overlapping numbers, and check whether it's over k.
        for (int i = 1; i < n - m + 1; i++) {
            if (b[a[i - 1]] > 0 && a_map[a[i - 1]] <= b[a[i - 1]]) {
                overlaps--;
            }
            a_map[a[i - 1]]--;
            a_map[a[i + m - 1]]++;
            if (b[a[i + m - 1]] > 0 && a_map[a[i + m - 1]] <= b[a[i + m - 1]]) {
                overlaps++;
            }
            // cout << i << " " << overlaps << endl;
            if (overlaps >= k) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
