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

/*


*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({b[i], a[i]});
        }
        sort(v.begin(), v.end());
        int num_notified = 0;
        int total_cost = 0;
        int remaining = n - 1;
        // We need to notify at least one person

        for (int i = 0; i < n; i++) {
            if (v[i].first > p) {
                break;
            }
            total_cost += v[i].first * min(remaining, v[i].second);
            remaining -= min(remaining, v[i].second);
        }
        total_cost += (1 + remaining) * p;
        cout << total_cost << endl;
    }
    return 0;
}
