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
        int w[n];
        int h[n];
        int max_w = 0;
        int max_h = 0;
        for (int i = 0; i < n; i++) {
            cin >> w[i] >> h[i];
            max_w = max(w[i], max_w);
            max_h = max(h[i], max_h);
        }
        cout << 2 * max_w + 2 * max_h << endl;
    }

    return 0;
}
