#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
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
/*
The distance is at most by y - x.

However,if y-x is composite, you likely get closer than that.
The smallest prime factor is the biggest distance that you can have.

In the worst case, that distance is a relatively big prime (can be up to 1e7).
- We need to figure out a way to compute it

We need to find a way to compute where the thing is.

ex: 2 and 63 -> gcd(2,63) = 1

distance is 61, so at most a chain of 61 things.
gcd(2+x, 63+x) = 61

For each prime factor, check the next number that it arizes. it will be the min of that.


*/

using namespace std;

const int INF = 1e9;
const int N = 1e7 + 5;

int mind[N];

void precalc() {
    for (int i = 0; i < N; i++) {
        mind[i] = i;
    }

    for (int p = 2; p < N; p++) {
        if (mind[p] != p) {
            continue;
        }
        for (int d = 2 * p; d < N; d += p) {
            mind[d] = min(mind[d], p);
        }
    }
}

vector<int> get_primes(int v) {
    vector<int> ps;
    while (v > 1) {
        if (ps.empty() || ps.back() != mind[v]) {
            ps.push_back(mind[v]);
        }
        v /= mind[v];
    }
    return ps;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precalc();

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (y - x == 1) {
            cout << -1 << endl;
        } else {
            int dist = y - x;

            int next_val = y;
            for (auto factor : get_primes(dist)) {
                int next_x = x + (factor - (x % factor));
                if (x % factor == 0) {
                    next_x = x;
                }
                next_val = min(next_val, next_x);
            }
            cout << next_val - x << endl;
        }
    }

    return 0;
}
