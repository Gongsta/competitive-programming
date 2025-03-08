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

    int n;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    int ans = 0;
    int l = 0;
    int r = n - 1;
    int l_sum = d[l];
    int r_sum = d[r];
    while (l < r) {
        if (l_sum == r_sum) {
            ans = l_sum;
            l++;
            if (l < r) {
                l_sum += d[l];
            }
        } else if (l_sum < r_sum) {
            l++;
            if (l < r) {
                l_sum += d[l];
            }
        } else {
            r--;
            if (l < r) {
                r_sum += d[r];
            }
        }
    }
    cout << ans << endl;

    return 0;
}
