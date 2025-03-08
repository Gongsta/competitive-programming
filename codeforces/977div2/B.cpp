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

    /*
    All numbers need to be 0 <= x < n for them to contribute

    Max MEX is n.

    */

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int a[n];
        int freq[n];
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < n) {
                freq[a[i]]++;
            }
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            if (freq[i] == 0) {
                ans = i;
                break;
            } else if (freq[i] > 1) {
                if (i + x < n) {
                    freq[i + x] += freq[i] - 1;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
