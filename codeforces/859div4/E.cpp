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

int prefix(vector<int>& a, int l, int r) {
    if (l == 0) {
        return a[r];
    }
    return a[r] - a[l - 1];
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            a[i] += a[i - 1];
        }

        int l = 0;
        int r = n - 1;
        int ans = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int correct_weight = a[mid];
            cout << "? " << mid + 1 << " ";
            for (int i = 0; i <= mid; i++) {
                cout << i + 1 << " ";
            }
            cout << endl;
            int x;
            cin >> x;
            if (x == correct_weight) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = min(ans, mid);
            }
        }
        cout << "! " << ans + 1 << endl;
    }

    return 0;
}
