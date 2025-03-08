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
        int n;
        cin >> n;
        int a[n];
        int num_zeros = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) {
                num_zeros++;
            }
        }
        if (num_zeros == n) {
            cout << 0 << endl;
        } else {
            int nums = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] != 0 && (i == 0 || a[i - 1] == 0)) {
                    nums++;
                }
            }
            if (nums == 1) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
    }

    return 0;
}
