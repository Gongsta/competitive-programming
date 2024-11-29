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

bool check_col(vector<vector<char>>& c, char letter, int col) {
    for (int i = 0; i < c.size(); i++) {
        if (c[i][col] == letter) {
            return true;
        }
    }
    return false;
}

bool check_row(vector<vector<char>>& c, char letter, int row) {
    for (int j = 0; j < c[0].size(); j++) {
        if (c[row][j] == letter) {
            return true;
        }
    }
    return false;
}

char get_opp(char letter) {
    if (letter == 'W') {
        return 'B';
    }
    return 'W';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> c(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c[i][j];
            }
        }
        if (c[0][0] == c[n - 1][m - 1] || c[0][m - 1] == c[n - 1][0]) {
            cout << "YES" << endl;
        } else {
            // Check for complex diagonals
            // There are like 4 cases:
            bool works = false;
            if (c[0][0] == c[n - 1][0] && check_col(c, c[0][0], m - 1)) {
                works = true;
            } else if (c[0][m - 1] == c[n - 1][m - 1] && check_col(c, c[0][m - 1], 0)) {
                works = true;
            } else if (c[0][0] == c[0][m - 1] && check_row(c, c[0][0], n - 1)) {
                works = true;
            } else if (c[n - 1][0] == c[n - 1][m - 1] && check_row(c, c[n - 1][0], 0)) {
                works = true;
            }
            if (works) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            /*

            */
            // check for black
            // check for white
        }
    }

    return 0;
}
