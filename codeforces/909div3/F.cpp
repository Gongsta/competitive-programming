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
#include <vector>
// #include <unordered_map> // NEVER USE THOSE IN CP
// #include <unordered_set> // NEVER USE THOSE IN CP

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int d[q];
        for (int i = 0; i < q; i++) {
            cin >> d[i];
        }
        for (int i = 1; i <= n - 1; i++) {
            cout << i << " " << i + 1 << endl;
        }
        int leaf = n - 1;
        for (int i = 0; i < q; i++) {
            if (d[i] == leaf) {
                cout << "-1 -1 -1" << endl;
            } else {
                cout << n << " " << leaf << " " << d[i] << endl;
                leaf = d[i];
            }
        }
    }

    return 0;
}
