#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
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

typedef long long ll;

using namespace std;

vector<int> adj[200001];
ll a[200001];

bool possible(int node, ll min_val, ll penalty) {
    if (adj[node].empty()) {
        return (a[node] - penalty) >= min_val;
    } else {
        bool good = true;
        // Number to increment by
        ll pen = max(0ll, min_val - (a[node] - penalty)) + penalty;
        if (pen > 1e9) {
            return false;
        }
        for (auto x : adj[node]) {
            good = good && possible(x, 0, pen);
        }
        return good;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p[n];
        ll max_sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            max_sum += a[i];
            adj[i].clear();
        }
        for (int i = 1; i < n; i++) {
            cin >> p[i];
            p[i]--;  // 0-indexed
            adj[p[i]].push_back(i);
        }
        ll ans = a[0];
        ll l = a[0];
        ll r = max_sum;
        while (l <= r) {
            ll mid = (l + r) / 2;
            // cout << "Mid" << mid << endl;
            if (possible(0, mid, 0)) {
                ans = max(ans, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
