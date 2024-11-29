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

int arr[(int)2e5 + 1];

int prefix(int l, int r) {
    if (l == 0) {
        return arr[r];
    } else if (l > r) {
        return 0;
    }
    return arr[r] - arr[l - 1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, v;
        cin >> n >> m >> v;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i == 0) {
                arr[i] = a[i];
            } else {
                arr[i] = a[i] + arr[i - 1];
            }
        }
        int segments = 0;
        int cumsum = 0;
        stack<int> pointers;
        for (int i = 0; i < n; i++) {
            cumsum += a[i];
            if (cumsum >= v) {
                if (segments < m) {  // Greedily create the segments
                    pointers.push(i);
                }
                segments++;
                cumsum = 0;
            }
        }
        if (segments < m) {  // impossible
            cout << -1 << endl;
        } else {
            int ans = prefix(pointers.top() + 1, n - 1);  // this is whatever alice can have

            // move the pointers to the right greedily while maintining
            int right = n - 1;
            while (!pointers.empty()) {
                int p = pointers.top();
                pointers.pop();
                int prev = -1;
                if (!pointers.empty()) {
                    prev = pointers.top();
                }
                while (p < right && prefix(p + 1, right) >= v) {
                    cout << prev << " " << p << endl;
                    ans = max(ans, prefix(prev + 1, p));
                    cout << ans << endl;
                    right = p;
                    p++;
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}
