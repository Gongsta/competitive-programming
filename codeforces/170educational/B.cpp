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

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

/* imagine rows are n, columns are k

First row is
- (n = 0)
1 (n = 1)
1 2  (n = 2)
1 2 4 (n = 3)
1 2 4 8 (n = 4)
1 2 4 8 16
1 2 4 8 16 32

k -> 2^k % 10e9
*/

int MOD = 1e9 + 7;
int binpow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int res = binpow(a, b / 2) % MOD;
    if (b % 2ll) {
        return (((res * res) % MOD) * a) % MOD;
    } else {
        return (res * res) % MOD;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int n[t];
    int k[t];

    for (int i = 0; i < t; i++) {
        cin >> n[i];
    }
    for (int i = 0; i < t; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < t; i++) {
        cout << binpow(2, k[i]) << endl;
    }

    return 0;
}
