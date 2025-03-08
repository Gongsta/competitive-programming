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
        int n, m;
        cin >> n >> m;
        int a[n][m];
        string dir_str;
        cin >> dir_str;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        int x[n + m - 1];
        pair<int, int> curr_pos;

        for (int i = 0; i <= dir_str.size(); i++) {
            char curr_dir = dir_str[min(i, (int)dir_str.size() - 1)];
            // do calculations and store values
            int sum = 0;
            if (curr_dir == 'D') {  // A corner where we are moving right now
                // sum over row
                for (int col = 0; col < m; col++) {
                    if (col != curr_pos.second) {
                        sum += a[curr_pos.first][col];
                    }
                }
            } else {
                // sum over column
                for (int row = 0; row < n; row++) {
                    if (row != curr_pos.first) {
                        sum += a[row][curr_pos.second];
                    }
                }
            }

            a[curr_pos.first][curr_pos.second] = -sum;
            if (curr_dir == 'D') {
                curr_pos.first++;
            } else {
                curr_pos.second++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
