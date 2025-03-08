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
        int n, k;
        cin >> n >> k;
        int c[n];
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            m[c[i]].push_back(i);
        }
        int ans = n;
        for (auto &x : m) {
            priority_queue<int> pq;
            pq.push(x.second[0]);
            for (int i = 0; i < x.second.size() - 1; i++) {
                pq.push(x.second[i + 1] - x.second[i] - 1);
            }
            pq.push(n - 1 - x.second[x.second.size() - 1]);
            int top = pq.top();
            pq.pop();
            ans = min(ans, max(top / 2, pq.top()));
        }
        cout << ans << endl;
    }

    return 0;
}
