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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 1;
        for (int k = 1; k <= n; k++) {
            bool ends[n];
            bool works = true;
            bool flipped = false;
            memset(ends, 0, sizeof(ends));
            for (int i = 0; i < n; i++) {
                if (ends[i]) {
                    flipped = !flipped;
                }

                if ((s[i] == '0' && !flipped) ||
                    (s[i] == '1' && flipped)) {
                    if (i + k > n) {
                        // doesn't worK
                        works = false;
                        break;
                    } else if (i + k < n) {
                        ends[i + k] = true;
                    }
                    flipped = !flipped;
                }
            }
            if (works) {
                ans = k;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
