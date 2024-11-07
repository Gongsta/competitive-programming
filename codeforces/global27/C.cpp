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
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                ans = ans & i;
            } else {
                ans = ans | i;
            }
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
