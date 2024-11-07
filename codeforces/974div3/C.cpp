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
        ll n;
        cin >> n;
        ll a[n];
        ll cumsum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cumsum += a[i];
        }
        int threshold = n / 2;
        if (n == 1 || n == 2) {
            cout << -1 << endl;
        } else {
            sort(a, a + n);
            ll min_val = a[threshold];
            if (2ll * n * min_val < cumsum) {
                cout << 0 << endl;
            } else {
                ll min_a_n = 2ll * n * min_val - (cumsum - a[n - 1]) + 1;
                cout << min_a_n - a[n - 1] << endl;
            }
        }
    }

    return 0;
}
