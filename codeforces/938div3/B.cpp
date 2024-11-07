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

    int t;
    cin >> t;
    while (t--) {
        int n, c, d;
        cin >> n >> c >> d;
        map<int, int> ref;
        map<int, int> target;

        int min_val = 1e9;
        for (int i = 0; i < n * n; i++) {
            int b;
            cin >> b;
            min_val = min(min_val, b);
            ref[b]++;
        }
        int a[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    a[i][j] = min_val;
                } else if (j == 0) {
                    a[i][j] = a[i - 1][j] + c;
                } else {
                    a[i][j] = a[i][j - 1] + d;
                }
                target[a[i][j]]++;
            }
        }

        bool works = true;
        for (auto x : target) {
            if (x.second != ref[x.first]) {
                works = false;
                break;
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
