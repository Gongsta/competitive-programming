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

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int ans;
    cin >> ans;
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int l = 2;
        int r = 999;
        int ans = -1;
        while (l <= r) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;

            // cout << m1 << " " << m2 << endl;
            int query_val = query(m1, m2);
            if (query_val == (m1 + 1) * (m2 + 1)) {
                r = m1 - 1;
                ans = m1;
            } else if (query_val == (m1) * (m2 + 1)) {
                l = m1 + 1;
                r = m2 - 1;
                ans = m2;
            } else {  // both correct
                l = m2 + 1;
            }
        }
        cout << "! " << ans << endl;
    }

    return 0;
}
