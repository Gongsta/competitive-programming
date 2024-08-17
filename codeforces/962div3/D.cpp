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
        ll n, x;
        cin >> n >> x;
        ll ans = 0;
        for (ll a = 1; a <= n; a++) {
            for (ll b = 1; b <= n / a; b++) {
                ans += min(max((x - a - b), 0ll), max(((n - a * b) / (a + b)), 0ll));
            }
        }
        cout << ans << endl;
    }

    return 0;
}
