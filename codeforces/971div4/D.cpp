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

ll choose(ll n, ll k) {
    if (k == 0) {
        return 1;
    }
    return (n * choose(n - 1, k - 1)) / k;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        set<pair<int, int>> s;
        ll n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            s.insert({x, y});
        }
        ll vertical_lines = 0;
        ll num_y = 0;
        for (auto i = s.begin(); i != prev(s.end()); i++) {
            if (i->first == next(i)->first) {
                vertical_lines++;
            }
        }
        for (auto it = s.begin(); it != s.end(); it++) {
            if (s.count({it->first - 1, (it->second + 1) % 2}) && s.count({it->first + 1, (it->second + 1) % 2})) {
                num_y++;
            }
        }
        ll ans = vertical_lines * (n - 2) + num_y;
        cout << ans << endl;
    }

    return 0;
}
