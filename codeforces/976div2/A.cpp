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
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << n << endl;
        } else {
            int ans = 0;
            int max_k = k;
            while (max_k * k <= n) {
                max_k *= k;
            }
            while (n > 0) {
                while (max_k > n && max_k >= k * k) {
                    max_k /= k;
                }
                if (max_k > n) {
                    ans += n;
                    n = 0;
                } else {
                    ans++;
                    n -= max_k;
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}
