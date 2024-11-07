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
        ll n, m, q;
        cin >> n >> m >> q;
        vector<ll> b(m, 0);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        while (q--) {
            int a;
            cin >> a;
            auto it = std::lower_bound(b.begin(), b.end(), a);
            int idx = it - b.begin();
            if (idx == m) {  // a is the biggest
                cout << n - b[m - 1] << endl;
            } else if (b[idx] == a) {
                cout << 0 << endl;
            } else if (idx == 0) {  // a is smaller than all values
                cout << b[idx] - 1 << endl;
            } else {
                ll mid = (b[idx - 1] + b[idx]) / 2;
                cout << min(b[idx] - mid, mid - b[idx - 1]) << endl;
            }
        }
    }

    return 0;
}
