#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
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

int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - k + i) / i;
    }
    return (int)(res + 0.01);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        ll a[n + 1];
        ll prefix[n + 2];
        prefix[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            prefix[i] = prefix[i - 1] + a[i];
        }
        sort(a + 1, a + n + 1);  // you can't sort it
        ll ans = 0;
        for (int i = (k + 1) / 2; i <= n - (k + 1) / 2 + 1; i++) {
            // ans += (C(i - 1, (k + 1) / 2 - 1) * C(n - i, (k + 1) / 2 - 1));
            if (a[i] == 0) {

                ans += ((ll)C(i - 1, (k + 1) / 2 - 1) * (ll)C(n - i, (k + 1) / 2 - 1)) * (a[i]) % ((ll)1e9 + 7ll);
            } else {
                ans += ((ll)C(i - 1, (k + 1) / 2 - 1) * (ll)C(n - i, (k + 1) / 2 - 1)) * (a[i]) % ((ll)1e9 + 7ll);
            }
            // cout << "ans" << ans << endl;
            ans = ans % ((ll)1e9 + 7ll);
        }
        cout << ans << endl;
    }

    return 0;
}
