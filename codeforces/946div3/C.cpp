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

typedef long long ll;

using namespace std;

int main() {
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
        map<tuple<int, int, int>, int> m;

        ll ans = 0;
        for (int i = 0; i < n - 2; i++) {
            ans += (m[{0, a[i + 1], a[i + 2]}] - m[{a[i], a[i + 1], a[i + 2]}]);
            ans += (m[{a[i], 0, a[i + 2]}] - m[{a[i], a[i + 1], a[i + 2]}]);
            ans += (m[{a[i], a[i + 1], 0}] - m[{a[i], a[i + 1], a[i + 2]}]);

            m[{a[i], a[i + 1], a[i + 2]}]++;
            m[{0, a[i + 1], a[i + 2]}]++;
            m[{a[i], 0, a[i + 2]}]++;
            m[{a[i], a[i + 1], 0}]++;
        }
        cout << ans << endl;
    }

    return 0;
}
