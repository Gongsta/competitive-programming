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

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        int b[n][m];
        map<int, int> rows_a;
        map<int, int> cols_a;
        map<int, int> rows_b;
        map<int, int> cols_b;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                rows_a[a[i][j]] = i;
                cols_a[a[i][j]] = j;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> b[i][j];
            }
        }

        bool works = true;
        // check rows
        for (int i = 0; i < n; i++) {
            int ii = rows_a[b[i][0]];
            for (int j = 0; j < m; j++) {
                if (rows_a[b[i][j]] != ii) {
                    works = false;
                    break;
                }
            }
        }
        // Check cols
        for (int j = 0; j < m; j++) {
            int jj = cols_a[b[0][j]];
            for (int i = 0; i < n; i++) {
                if (cols_a[b[i][j]] != jj) {
                    works = false;
                    break;
                }
            }
        }

        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;

        }
    }

    return 0;
}
