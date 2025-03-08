#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
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

int lsqrt(int num) {
    int l = 1;
    int r = min(num, (int)1e9);
    int ans = 1;
    while (l <= r) {
        int mid = (l + r) / 2ll;
        if (mid * mid <= num) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int cnt = 0;
        int num_l = lsqrt(l);
        int num_r = lsqrt(r);
        if (num_l == num_r) {
            for (int i = 0; i < 3; i++) {
                if (num_l * (num_l + i) >= l && num_r * (num_r + i) <= r) {
                    cnt++;
                }
            }
        } else {
            for (int i = 0; i < 3; i++) {
                int new_num_l = num_l * (num_l + i);
                int new_num_r = num_r * (num_r + i);
                if (new_num_l >= l) {
                    cnt++;
                }
                if (new_num_r <= r) {
                    cnt++;
                }
            }

            if (num_r - num_l >= 1) {
                cnt += (num_r - num_l - 1ll) * 3ll;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
