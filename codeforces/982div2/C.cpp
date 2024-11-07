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
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int computed_a[n + 1];
        for (int i = 1; i <= n; i++) {
            int target_a = n + 1 - i;
            computed_a[i] = target_a - a[i];
        }

        map<int, vector<int>> adj;

        for (int i = 2; i <= n; i++) {
            if (computed_a[i] > 0) {  // impossible if you add zeros to to make equal to 0
                continue;
            }
            computed_a[i] = -computed_a[i];  // turn positive
            adj[computed_a[i]].push_back(computed_a[i] + (i - 1));
        }
        queue<int> q;
        set<int> visited;
        visited.insert(0);
        q.push(0);
        int max_extra_zeros = 0;

        while (!q.empty()) {
            int val = q.front();
            max_extra_zeros = max(max_extra_zeros, val);
            q.pop();
            for (auto x : adj[val]) {
                if (visited.count(x)) {
                    continue;
                }
                visited.insert(x);
                q.push(x);
            }
        }
        cout << n + max_extra_zeros << endl;
    }

    return 0;
}
