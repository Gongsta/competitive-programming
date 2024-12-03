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

int xors[(int)2e5];

int get_xor(int l, int r, int n) {
    if (l == 0) {
        return xors[r];
    }
    return xors[r] ^ xors[l - 1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n; i++) {
            cin >> xors[i];
            if (i != 0) {
                xors[i] ^= xors[i - 1];
            }
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
        }
    }

    return 0;
}
