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
/*
Your can change values at any a_i = 0
So those are your decision points.

You goal is to choose a value that maximizes from this current interval to the next interval that a_i appears

you store a current sum.
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        int curr_sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                map<int, int> m;
                m[curr_sum]++;
                int local_sum = curr_sum;
                for (int j = i + 1; j < n; j++) {
                    if (a[j] == 0) {
                        break;
                    }
                    local_sum += a[j];
                    m[local_sum]++;
                }
                int max_seen = 0;
                int num = 0;
                for (auto x : m) {
                    if (x.second > max_seen) {
                        max_seen = x.second;
                        num = x.first;
                    }
                }
                a[i] = -num;
            }
            curr_sum += a[i];
            if (curr_sum == 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
