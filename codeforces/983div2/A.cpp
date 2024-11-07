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
        int a[2 * n];
        int total_on = 0;
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                total_on++;
            }
        }
        int total_off = 2 * n - total_on;
        cout << total_on % 2ll << " " << min(total_off, total_on) << endl;
    }

    return 0;
}
