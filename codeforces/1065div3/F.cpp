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

/*
for each number, if there exists a number bigger than current number on the right, or smaller number on the left, then it works
*/
using namespace std;

void solve() {
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<pair<int, int>> segments;
    vector<pair<int, int>> edges;
    int start = p[0];
    for (int i = 1; i < n; i++) {
        if (p[i] < p[i - 1]) {
            segments.push_back({start, p[i - 1]});
            start = p[i];
        } else {
            edges.push_back({p[i - 1], p[i]});
        }
    }
    segments.push_back({start, p[n - 1]});
    int m = segments.size();

    if (m == 1) {
        cout << "Yes" << endl;
        for (auto& v : edges) {
            cout << v.first << " " << v.second << endl;
        }
        return;
    }
    int smallest = segments[0].first;
    queue<int> q;

    for (int i = 1; i < m; i++) {
        if (segments[i].second > smallest) {
            edges.push_back({smallest, segments[i].second});
            while (!q.empty()) {
                edges.push_back({q.front(), segments[i].second});
                smallest = min(smallest, q.front());
                q.pop();
            }
            smallest = min(smallest, segments[i].first);
        } else {
            q.push(segments[i].first);  // Even smaller value that is pending
        }
    }
    if (!q.empty()) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (auto& v : edges) {
            cout << v.first << " " << v.second << endl;
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
