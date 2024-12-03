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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        int n;
        cin >> n;
        int grid[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        // Check diagonals from row
        for (int i = 0; i < n; i++) {
            int smallest = 0;
            for (int k = 0; k < n; k++) {
                if (i + k >= n) {
                    break;
                }
                smallest = min(smallest, grid[i + k][k]);
            }
            ans += -smallest;
        }
        // Check diagonals from col
        for (int j = 1; j < n; j++) {
            int smallest = 0;
            for (int k = 0; k < n; k++) {
                if (j + k >= n) {
                    break;
                }
                smallest = min(smallest, grid[k][j + k]);
            }
            ans += -smallest;
        }
        cout << ans << endl;
    }

    return 0;
}
