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
        ll n, m;
        cin >> n >> m;
        ll a[n];
        ll b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        ll ans = 0;
        for (int i = n - 1; i > m - 1; i--) {
            ans += min(a[i], b[i]);
        }
        ll to_add = a[m - 1];
        ll b_sum = 0;
        for (int i = m - 1; i > 0; i--) {
            b_sum += b[i];
            to_add = min(to_add, b_sum + a[i - 1]);
        }

        cout << ans + to_add << endl;
    }

    return 0;
}
