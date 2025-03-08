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
    /*
    1 3 9 27
    */
    while (t--) {
        int n, x;
        cin >> n >> x;
        int a[n];
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]]++;
        }
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            if (m[x * a[i]] > 0 && m[a[i]] > 0) {
                m[a[i]]--;
                m[x * a[i]]--;
            }
        }
        int extras = 0;
        for (auto v : m) {
            extras += v.second;
        }
        cout << extras << endl;
    }

    return 0;
}
