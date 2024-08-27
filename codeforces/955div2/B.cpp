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
        ll x, y, k;
        cin >> x >> y >> k;
        while (k > 0) {
            ll new_x = x + max(1ll, min(k, y - (x % y)));
            k -= max(1ll, min(k, y - (x % y)));
            x = new_x;
            while (x % y == 0) {
                x /= y;
            }
            // cout << x << " " << k << endl;
            if (x == 1) {
                break;
            }
        }
        if (k > 0) {
            x += k % (y - 1);
        }
        cout << x << endl;
    }

    return 0;
}
