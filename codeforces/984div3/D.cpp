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

bool in_bounds(vector<vector<char>>& carpet, int i, int j) {
    return i >= 0 && i < carpet.size() && j >= 0 && j < carpet[0].size();
}

bool in_bounds(vector<vector<char>>& carpet, int i, int j, int min_i, int max_i, int min_j, int max_j) {
    return i >= min_i && i < max_i && j >= min_j && j < max_j;
}

bool is_1543(queue<char> q) {
    if (q.size() < 4) {
        return false;
    }
    char val1 = q.front();
    q.pop();
    if (val1 != '1') {
        return false;
    }
    char val2 = q.front();
    q.pop();
    if (val2 != '5') {
        return false;
    }
    char val3 = q.front();
    q.pop();
    if (val3 != '4') {
        return false;
    }
    char val4 = q.front();
    q.pop();
    if (val4 != '3') {
        return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> carpet(n, vector<char>(m, 0));
        int ans = 0;

        vector<vector<int>> dirs = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> carpet[i][j];
            }
        }
        /*
        for the current layer: i -> n - 1 - i
        j -> m - 1 - j
        */
        set<pair<int, int>> s;
        for (int k = 0; k < min(n / 2, m / 2); k++) {
            int curr_i = k;
            int curr_j = k;
            int curr_dir_idx = 0;
            map<pair<int, int>, int> visited;
            queue<char> q;
            while (visited[{curr_i, curr_j}] < 2) {
                visited[{curr_i, curr_j}]++;
                q.push(carpet[curr_i][curr_j]);
                if (q.size() > 4) {
                    q.pop();
                }
                if (is_1543(q) && !s.count({curr_i, curr_j})) {
                    ans++;
                    s.insert({curr_i, curr_j});
                }

                vector<int> dir = dirs[curr_dir_idx];
                // Change direction
                if (!in_bounds(carpet, curr_i + dir[0], curr_j + dir[1],
                               k, n - k, k, m - k)) {
                    curr_dir_idx = (curr_dir_idx + 1) % 4;
                    dir = dirs[curr_dir_idx];
                }
                // update the position
                curr_i += dir[0];
                curr_j += dir[1];
                if (!in_bounds(carpet, curr_i, curr_j,
                               k, n - k, k, m - k)) {
                    break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
