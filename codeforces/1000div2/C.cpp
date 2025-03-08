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
        int n;
        cin >> n;
        set<int> adj[n];
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        map<int, vector<int>, greater<int>> largests;
        for (int i = 0; i < n; i++) {
            largests[adj[i].size()].push_back(i);
        }
        int ans = largests.begin()->first;  // we always greedily take the first largest node

        vector<int> firsts;
        vector<int> seconds;
        if (largests.begin()->second.size() == 1) {  // get the second largest
            auto p = largests.begin();
            firsts.push_back(p->second[0]);
            p++;  // second largest size
            seconds = p->second;
        } else {
            // 2 values is enough
            firsts.push_back(largests.begin()->second[0]);
            firsts.push_back(largests.begin()->second[1]);
            seconds = largests.begin()->second;
        }
        int second_size = 0;

        bool found = false;
        for (auto first : firsts) {
            for (auto second : seconds) {
                if (first == second) {
                    continue;
                }
                if (adj[first].count(second)) {
                    second_size = (int)adj[second].size() - 2;
                } else {
                    second_size = (int)adj[second].size() - 1;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        ans += second_size;

        cout << ans << endl;
    }
    return 0;
}
