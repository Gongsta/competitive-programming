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
        ll n, m, q;
        cin >> n >> m >> q;
        ll b[m];
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(b, b + m);
        while (q--) {
            int a;
            cin >> a;
            if (a == b[0] || a == b[1]) {
                cout << 0 << endl;
            } else if (a < b[0]) {
                cout << b[0] - 1 << endl;
            } else if (a > b[0] && a < b[1]) {
                ll mid = (b[0] + b[1]) / 2;
                cout << min(b[1] - mid, mid - b[0]) << endl;
            } else {
                cout << n - b[1] << endl;
            }
        }
    }

    return 0;
}
