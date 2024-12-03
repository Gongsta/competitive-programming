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

vector<vector<int>> dirs = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},

};

bool in_bounds(int i, int j, int rows, int cols) {
    return i >= 0 && i < rows && j >= 0 && j < cols;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string grid[2];
        cin >> grid[0];
        cin >> grid[1];
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        q.push({0, 0});
        visited.insert({0, 0});
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            for (auto& dir : dirs) {
                int new_i = v.first + dir[0];
                int new_j = v.second + dir[1];
                if (in_bounds(new_i, new_j, 2, n)) {
                    // Do another step
                    if (grid[new_i][new_j] == '<') {
                        new_j--;
                    } else {
                        new_j++;
                    }
                    if (!visited.count({new_i, new_j})) {
                        // cout << new_i << " " << new_j << endl;
                        visited.insert({new_i, new_j});
                        q.push({new_i, new_j});
                    }
                }
            }
        }

        if (visited.count({1, n - 1})) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
