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

    int n, m;
    cin >> n >> m;
    set<int> alive;
    for (int i = 1; i <= n; i++) {
        alive.insert(i);
    }
    int ans[n + 1];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        auto curr = alive.lower_bound(l);
        vector<int> dead;
        while (curr != alive.end() && *curr <= r) {
            dead.push_back(*curr);
            curr = alive.lower_bound(*curr + 1);
        }
        for (auto d : dead) {
            if (d != x) {
                alive.erase(d);
                ans[d] = x;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
