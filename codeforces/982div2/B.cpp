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

/*
Idea: Get the position of the number if it was sorted.
And get its index.

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
        int ans = n;
        for (int i = 0; i < n; i++) {
            int left_ans = i;
            // Assume this number is the largest
            int right_ans = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[i]) {
                    right_ans++;
                }
            }
            ans = min(ans, left_ans + right_ans);
        }
        cout << ans << endl;
    }

    return 0;
}
