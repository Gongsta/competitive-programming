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

/*

6 = 1 x 2 x 3

How do we brute force this?
*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll x[3];
        ll k;
        cin >> x[0] >> x[1] >> x[2] >> k;
        sort(x, x + 3);
        ll side[3];
        ll ans = 0;
        for (ll i = 1; i <= sqrt(k); i++) {
            if (k % i != 0) {
                continue;
            }
            for (ll j = i; j <= sqrt(k / i); j++) {
                if ((k / i) % j != 0) {
                    continue;
                }
                side[0] = i;
                side[1] = min(j, (k / i) / j);
                side[2] = max(j, (k / i) / j);

                if (x[0] < side[0] || x[1] < side[1] || x[2] < side[2]) {
                    continue;
                }
                ans = max(ans, ((x[0] - side[0] + 1ll) * (x[1] - side[1] + 1ll) * (x[2] - side[2] + 1ll)));
            }
        }
        cout << ans << endl;
    }

    return 0;
}
