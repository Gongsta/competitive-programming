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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;
    int a[n][k];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
            if (i > 0) {
                a[i][j] = a[i][j] | a[i - 1][j];
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < k; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<int> rs[k];
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < n; i++) {
            rs[j].push_back(a[i][j]);
        }
    }
    while (q--) {
        int m;
        cin >> m;
        int r, c;
        char o;
        int left = 1;
        int right = n;
        bool works = true;
        for (int z = 0; z < m; z++) {
            cin >> r >> o >> c;
            r--;
            if (o == '<') {
                auto it = lower_bound(rs[r].begin(), rs[r].end(), c);
                if (it != rs[r].begin()) {
                    it--;
                    right = min(right, (int)(it - rs[r].begin()) + 1);
                } else {
                    works = false;
                }

            } else {
                auto it = upper_bound(rs[r].begin(), rs[r].end(), c);
                if (it == rs[r].end()) {
                    works = false;
                } else {
                    left = max(left, (int)(it - rs[r].begin()) + 1);
                }
            }
        }
        if (works && left <= right) {
            cout << left << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
