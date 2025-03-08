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
Consider the values of indices
1 2 2 3 4 5 6

You get
(6 - 1) + (6 - 2 ) + (6 -2) +...

let's say the values are sorted. Then
The contribution of
v_i is i * v_i (with 0-indexed)
We subtract each i (n - i - 1) times,

so total, we have
v_i * i - ((n - i -1) * v_i) =

(v[i] * (2* i - n + 1))
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int grid[n][m];
    map<int, vector<int>> rows;
    map<int, vector<int>> cols;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            rows[grid[i][j]].push_back(i);
            cols[grid[i][j]].push_back(j);
        }
    }
    int ans = 0;
    for (auto &x : rows) {
        sort(x.second.begin(), x.second.end());
        for (int i = 0; i < x.second.size(); i++) {
            ans += x.second[i] * (2 * i - x.second.size() + 1);
        }
    }
    for (auto &x : cols) {
        sort(x.second.begin(), x.second.end());
        for (int i = 0; i < x.second.size(); i++) {
            ans += x.second[i] * (2 * i - x.second.size() + 1);
        }
    }
    cout << ans << endl;
    return 0;
}
