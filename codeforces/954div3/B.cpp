#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
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

typedef long long ll;

using namespace std;
/*
9 8 7
6 5 4
3 2 1

8 8 7





*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        vector<vector<int>> dirs = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int max_val = 0;
                for (auto &dir : dirs) {
                    if (i + dir[0] >= 0 && i + dir[0] <= n - 1 && j + dir[1] >= 0 && j + dir[1] <= m - 1) {
                        max_val = max(max_val, a[i + dir[0]][j + dir[1]]);
                    }
                }
                if (max_val < a[i][j]) {
                    a[i][j] = max_val;
                }
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
