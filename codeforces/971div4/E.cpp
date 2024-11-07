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

ll sum(ll l, ll r) {
    return ((r * (r + 1ll)) / 2ll) - (l * (l - 1)) / 2ll;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll l = k;
        ll r = k + n - 1;
        ll ans = r;
        while (l <= r) {
            ll mid = (l + r) / 2ll;
            ll diff1 = abs(sum(k, mid) - sum(mid + 1, k + n - 1));
            ll diff2 = abs(sum(k, mid + 1) - sum(mid + 2, k + n - 1));
            ans = min(min(ans, diff1), diff2);
            if (diff1 > diff2) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
