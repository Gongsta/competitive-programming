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
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int l = 0;
        int r = n - 1;
        bool on_left = true;

        while (l < r && k > 0) {
            if (on_left) {
                if (a[l] <= a[r]) {
                    k -= 2 * a[l] - 1;
                    on_left = false;
                    if (k < 0) {
                        break;
                    }
                    a[r] -= (a[l] - 1);
                    l++;
                } else {
                    k -= 2 * a[r];
                    if (k < 0) {
                        break;
                    }
                    a[l] -= a[r];
                    r--;
                }
            } else {
                if (a[r] <= a[l]) {
                    k -= 2 * a[r] - 1;
                    on_left = true;
                    if (k < 0) {
                        break;
                    }
                    a[l] -= (a[r] - 1);
                    r--;
                } else {
                    k -= 2 * a[l];
                    if (k < 0) {
                        break;
                    }
                    a[r] -= a[l];
                    l++;
                }
            }
        }

        if (l == r && k >= a[l]) {
            l++;
        }
        cout << n - (r - l + 1) << endl;
    }

    return 0;
}
