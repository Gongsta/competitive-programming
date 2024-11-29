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
Binary search the value of k for which it is possible.

- If the list is even, first goes with second, etc.
    - So just take the max(a[i] - a[i-1]) for i % 2 == 1
- Else, if odd, any of the numbers can go with another, which you get for free.
    - So it's the second biggest gap that you take
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

        if (n % 2 == 0) {
            int longest = a[1] - a[0];
            for (int i = 1; i < n; i += 2) {
                longest = max(longest, a[i] - a[i - 1]);
            }
            cout << longest << endl;
        } else {
            if (n == 1) {
                cout << 1 << endl;
            } else {
                int ans = a[n - 1] - a[0];
                for (int i = 0; i < n; i += 2) {
                    int longest = 0;
                    for (int j = 1; j < n; j += 2) {
                        if (j > i && j % 2 == 1) {
                            j++;
                        }
                        longest = max(longest, a[j] - a[j - 1]);
                    }
                    ans = min(ans, longest);
                }
                cout << ans << endl;
            }
        }
    }

    return 0;
}
