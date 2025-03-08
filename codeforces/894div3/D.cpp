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

int choose(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n) {
        return 0;
    }
    return (n * choose(n - 1, k - 1)) / k;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int l = 2;
        int r = min(n * 2ll, 2648956421ll);
        int min_num = l;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (choose(mid, 2) <= n) {
                min_num = max(min_num, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << min_num + n - choose(min_num, 2) << endl;
    }

    return 0;
}
