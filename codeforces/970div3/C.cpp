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
        ll l, r;
        cin >> l >> r;
        ll ans = 1;
        ll prev = l;
        ll dist = 0;
        while (true) {
            dist++;
            prev += dist;
            if (prev <= r) {
                ans++;
            } else {
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
