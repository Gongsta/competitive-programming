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
        int attempts = 0;
        int sum = 0;
        sort(a, a + n);
        if (a[0] * n >= k) {  // Just do everything in a round robin fashion, garanteed to hit
            cout << k << endl;
        } else {
            attempts = 0;
            sum = 0;
            int cum_sub = 0;
            for (int i = 0; i < n; i++) {
                int a_val = a[i] - cum_sub;
                if (a_val == 0) {
                    attempts++;
                    continue;
                }
                if (a_val * (n - i) + sum >= k) {
                    attempts += k - sum;  // whatever is left
                    break;
                } else {
                    cum_sub += a_val;
                    sum += a_val * (n - i);
                    attempts += a_val * (n - i);
                    attempts++;
                }
            }
            cout << attempts << endl;
        }
    }

    return 0;
}
