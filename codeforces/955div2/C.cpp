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

ll prefix_sum(int l, int r, vector<ll>& prefix) {
    if (l == 0) {
        return prefix[r];
    }
    return prefix[r] - prefix[l - 1];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, l, r;
        cin >> n >> l >> r;
        ll a[n];
        vector<ll> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        prefix[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = a[i] + prefix[i - 1];
        }
        int l_p = 0;
        int r_p = 0;
        int ans = 0;
        while (l_p < n && r_p < n) {
            if (l <= prefix_sum(l_p, r_p, prefix) && prefix_sum(l_p, r_p, prefix) <= r) {
                l_p = r_p + 1;
                r_p = l_p;
                ans++;
            } else if (prefix_sum(l_p, r_p, prefix) < l) {
                r_p++;
            } else {
                l_p++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
