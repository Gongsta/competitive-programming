#include <algorithm>
#include <bitset>
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll a[n];
        unordered_map<ll, ll> c;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            ll num;
            cin >> num;
            c[a[i]] = num;
        }
        sort(a, a + n);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll n1 = min(c[a[i]], m / a[i]);
            ll coins_used = n1 * a[i];
            if (i + 1 < n && a[i + 1] == a[i] + 1) {
                ll n2 = min(c[a[i + 1]], (m - coins_used) / a[i + 1]);
                ll coins_used2 = n2 * a[i + 1];
                ll remainder_coins = m - coins_used - coins_used2;

                ll shift = min(min(remainder_coins, n1), c[a[i + 1]] - n2);
                ll final_coins = (n1 - shift) * a[i] + (n2 + shift) * a[i + 1];
                ans = max(ans, final_coins);
                // cout << n1 << " " << coins_used << endl;
                // cout << n2 << " " << coins_used2 << endl;

            } else {
                ans = max(ans, coins_used);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
