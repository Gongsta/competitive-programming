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
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            bool works = true;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (abs(a[i] - a[j]) % k == 0) {
                    works = false;
                    break;
                }
            }
            if (works) {
                ans = i + 1;
                break;
            }
        }
        if (ans == -1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << ans << endl;
        }
    }

    return 0;
}
