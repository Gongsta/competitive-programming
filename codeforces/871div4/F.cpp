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
        int n, m;
        cin >> n >> m;
        vector<int> adj[n];
        while (m--) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int middle = 0;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) {
                middle = adj[i][0];
                break;
            }
        }
        int root = 0;
        for (auto v : adj[middle]) {
            if (adj[v].size() != 1) {
                root = v;
                break;
            }
        }
        cout << adj[root].size() << " " << adj[middle].size() - 1 << endl;
    }

    return 0;
}
