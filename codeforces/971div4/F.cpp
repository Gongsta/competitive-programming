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

ll prefix_sum(vector<ll>& prefix, int l, int r) {
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
        ll n, q;
        cin >> n >> q;
        vector<ll> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i != 0) {
                a[i] += a[i - 1];
            }
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            int c_idx = l / n;
            int start = l % n;
            if (start == 0) {
                start += n;
            }
            ll num_contig = (r - l) / n;
        }
    }

    return 0;
}
