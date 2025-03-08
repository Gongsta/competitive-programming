#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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
    /*
    Use a map and count the occurences. You will always do the smallest and
    go until the end. So remove the smallest first.

    The answer if k=0 is to count the number of unique elements.

    If you have k = 5 for example, does greedy work? Yes, as long as you try from smallest count to biggest count
    */
    while (t--) {
        map<int, int> m;
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]]++;
        }
        vector<pair<int, int>> v;
        for (auto x : m) {
            v.push_back({x.second, x.first});
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for (auto x : v) {
            if (k >= x.first) {
                k -= x.first;
            } else {
                ans++;
            }
        }
        cout << max(ans, 1ll) << endl;
    }

    return 0;
}
