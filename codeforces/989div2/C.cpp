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

map<pair<int, int>, bool> exited;
set<pair<int, int>> visited;

bool in_bounds(int i, int j, int n_rows, int n_cols) {
    return i >= 0 && i < n_rows && j >= 0 && j < n_cols;
}

pair<int, int> get_dir(char c) {
    if (c == 'U') {
        return {-1, 0};
    } else if (c == 'D') {
        return {1, 0};
    } else if (c == 'L') {
        return {0, -1};
    } else {
        return {0, 1};
    }
}

bool dfs(vector<vector<char>>& grid, int i, int j) {
    if (grid[i][j] == '?') {
        return false;
    }
    if (exited.count({i, j})) {
        return exited[{i, j}];
    }
    if (visited.count({i, j})) {  // not in the exited list, but visited before, so part of the cycle
        return false;
    }

    visited.insert({i, j});

    auto dir = get_dir(grid[i][j]);
    int new_i = i + dir.first;
    int new_j = j + dir.second;
    if (!in_bounds(new_i, new_j, grid.size(), grid[0].size())) {
        exited[{i, j}] = true;
    } else {
        exited[{i, j}] = dfs(grid, new_i, new_j);
    }
    return exited[{i, j}];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        visited.clear();
        exited.clear();
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '?'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '?') {
                    continue;
                }
                dfs(grid, i, j);
            }
        }

        vector<vector<int>> dirs = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0},
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '?') {
                    bool has_cycle = false;
                    for (auto& dir : dirs) {
                        int new_i = i + dir[0];
                        int new_j = j + dir[1];
                        if (in_bounds(new_i, new_j, n, m) && (grid[new_i][new_j] == '?' || !exited[{new_i, new_j}])) {
                            has_cycle = true;
                        }
                    }
                    if (!has_cycle) {
                        exited[{i, j}] = true;
                    }
                }
            }
        }

        int num_exited = 0;
        for (auto& x : exited) {
            if (x.second) {
                num_exited++;
            }
        }
        cout << n * m - num_exited << endl;
    }

    return 0;
}
