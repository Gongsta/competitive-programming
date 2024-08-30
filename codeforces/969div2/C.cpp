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
        ll n, a, b;
        cin >> n >> a >> b;
        ll c[n];
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        sort(c, c + n);
        ll g = gcd(a, b);
        set<ll> gcds;
        for (int i = 0; i < n; i++) {
            gcds.insert(c[i] % g);
        }
        vector<ll> v_gcds;
        for (auto g : gcds) {
            v_gcds.push_back(g);
        }
        ll ans = v_gcds[v_gcds.size() - 1] - v_gcds[0];
        for (int i = 1; i < v_gcds.size(); i++) {
            ans = min(ans, v_gcds[i - 1] + g - v_gcds[i]);
        }

        cout << ans << endl;
    }

    return 0;
}
