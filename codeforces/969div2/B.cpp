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
        int n, m;
        cin >> n >> m;
        ll a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll max_v = *max_element(a, a + n);
        while (m--) {
            string op;
            ll l_v, r_v;
            cin >> op >> l_v >> r_v;
            if (l_v <= max_v && max_v <= r_v) {
                if (op == "-") {
                    max_v--;
                } else {
                    max_v++;
                }
            }
            cout << max_v << " ";
        }
        cout << endl;
    }

    return 0;
}
