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

int compute_suffix(vector<int>& suffix, int l, int r, int n) {
    if (r == n - 1) {
        return suffix[l];
    }
    return suffix[l] - suffix[r + 1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
    1 3, 2 4

    k == 0 -> 1 group (not even an option)
    k == 1 -> 2 or more group. You can binary search the groups

    check the case
    10 1
    1010010011

    */
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        char s[n];
        vector<int> bob(n + 1, 0);
        vector<int> alice(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                bob[i] = 1 + bob[i + 1];
                alice[i] = alice[i + 1];
            } else {
                bob[i] = bob[i + 1];
                alice[i] = 1 + alice[i + 1];
            }
        }
        vector<int> suffixes;
        for (int i = n - 1; i > 0; i--) {
            suffixes.push_back(bob[i] - alice[i]);
        }

        sort(suffixes.begin(), suffixes.end());
        reverse(suffixes.begin(), suffixes.end());
        int total = 0;
        int ans = 1;
        for (int& suffix : suffixes) {
            total += suffix;
            ans++;
            if (total >= k) {
                break;
            }
        }
        if (total >= k) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
