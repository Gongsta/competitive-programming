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
        int n, m1, m2;
        cin >> n >> m1 >> m2;
        set<int> F[n];
        set<int> G[n];
        for (int i = 0; i < m1; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            F[u].insert(v);
            F[v].insert(u);
        }
        int ans = 0;

        for (int i = 0; i < m2; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            G[u].insert(v);
            G[v].insert(u);
        }
        bool processed[n];
        memset(processed, 0, sizeof(processed));
        for (int curr = 0; curr < n; curr++) {
            if (processed[curr]) {
                continue;
            }
            // Collect the G_components
            set<int> G_component;
            queue<int> q;
            q.push(curr);
            G_component.insert(curr);
            processed[curr] = true;
            while (!q.empty()) {
                auto x = q.front();
                q.pop();
                for (auto v : G[x]) {
                    if (processed[v]) {
                        continue;
                    }
                    processed[v] = true;
                    G_component.insert(v);
                    q.push(v);
                }
            }

            set<int> visited;

            // Go through F and remove any edges that are not in component G. Traverse nodes that are in same component as G
            q.push(curr);
            visited.insert(curr);
            vector<pair<int, int>> to_rm;
            while (!q.empty()) {
                auto x = q.front();
                q.pop();
                for (auto v : F[x]) {
                    if (!G_component.count(v)) {
                        // remove the edge
                        to_rm.push_back({x, v});
                    } else {
                        if (!visited.count(v)) {
                            visited.insert(v);
                            q.push(v);
                        }
                    }
                }
            }

            // Add an edge for all remaining vertices in G_component, but not in visited (F_component)
            for (auto y : G_component) {
                if (!visited.count(y)) {
                    ans++;  // add an edge from x to G_component
                    queue<int> q;
                    q.push(y);
                    visited.insert(y);
                    while (!q.empty()) {
                        auto x = q.front();
                        q.pop();
                        for (auto v : F[x]) {
                            if (!G_component.count(v)) {
                                to_rm.push_back({x, v});
                            } else {
                                if (!visited.count(v)) {
                                    visited.insert(v);
                                    q.push(v);
                                }
                            }
                        }
                    }
                }
            }

            ans += to_rm.size();
            for (auto x : to_rm) {
                F[x.first].erase(x.second);
                F[x.second].erase(x.first);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
