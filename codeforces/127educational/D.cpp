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
Consider 1 10 1

where do you put 11, 12?
If it was 10 1 10, then do 10 1 10 11 12, easy

1 10 1 11 12 -> 9 + 9 + 10 + 1 = 29

or 1 10 11 12 1 -> 9 + 1 + 1 + 11 = 22
- This is wayyy better, so just putting on extremities is not good enoguh

So you have 2 different intervals.



Consider the input:
7 6 10

and x = 10
so you need to slot 1,2,3,4 somewhere.

*/
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int min_val = a[0];
        int max_val = a[0];
        for (int i = 0; i < n; i++) {
            min_val = min(min_val, a[i]);
            max_val = max(max_val, a[i]);
            if (i > 0) {
                ans += abs(a[i] - a[i - 1]);
            }
        }
        vector<vector<int>> intervals = {{1, min_val - 1}, {max_val + 1, x}};
        for (auto interval : intervals) {
            if (interval[0] > interval[1]) {
                continue;  // free
            }
            // [l, r] inclusive
            int l = interval[0];
            int r = interval[1];
            int sum = r - l + min(abs(a[0] - r), abs(a[0] - l));
            for (int i = 1; i < n; i++) {
                sum = min(sum, r - l + abs(a[i] - r) + abs(a[i - 1] - l) - abs(a[i] - a[i - 1]));
                sum = min(sum, r - l + abs(a[i] - l) + abs(a[i - 1] - r) - abs(a[i] - a[i - 1]));
            }
            sum = min(sum, r - l + min(abs(a[n - 1] - r), abs(a[n - 1] - l)));
            ans += sum;
        }
        cout << ans << endl;
    }

    return 0;
}
