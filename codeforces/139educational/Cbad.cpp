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
    {0, -1},
    {1, 0},
    {-1, 0},
};

bool in_bounds(int i, int j, int rows, int cols) {
    return i >= 0 && j >= 0 && i < rows && j < cols;
}
bool dfs(pair<int, int> curr, vector<string>& s, set<pair<int, int>>& visited, int num_b) {
    bool works = false;
    for (auto dir : dirs) {
        int row = curr.first + dir[0];
        int col = curr.second + dir[1];
        if (!visited.count({row, col}) && in_bounds(row, col, 2, s[0].size()) && s[row][col] == 'B') {
            visited.insert({row, col});
            works = works || dfs({row, col}, s, visited, num_b);
            visited.erase({row, col});
        }
    }

    if (visited.size() == num_b) {
        return true;
    }

    return works;
}

signed
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<string> s(2);
        for (int i = 0; i < 2; i++) {
            cin >> s[i];
        }
        int num_b = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == 'B') {
                    num_b++;
                }
            }
        }

        vector<pair<int, int>> starts;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == 'B') {
                    starts.push_back({i, j});
                    break;
                }
            }
        }

        for (int i = 0; i < 2; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i][j] == 'B') {
                    starts.push_back({i, j});
                    break;
                }
            }
        }
        bool works = false;
        for (auto start : starts) {
            set<pair<int, int>> visited;
            visited.insert(start);
            works = works || dfs(start, s, visited, num_b);
        }

        if (works || num_b == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
