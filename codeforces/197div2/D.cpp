#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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

void build(vector<int>& segtree, int i, int depth, int total_depth) {
    if (2 * i >= segtree.size()) {  // reached last layer, are done building
        return;
    }
    build(segtree, 2 * i, depth + 1, total_depth);
    build(segtree, 2 * i + 1, depth + 1, total_depth);
    if ((total_depth - depth) % 2 == 0) {
        segtree[i] = segtree[2 * i] ^ segtree[2 * i + 1];
    } else {
        segtree[i] = segtree[2 * i] | segtree[2 * i + 1];
    }
}

void update(vector<int>& segtree, int i, int depth, int total_depth, int l, int r, int pos, int val) {
    if (l == r) {
        segtree[i] = val;
    } else {
        int m = (l + r) / 2;
        if (pos <= m) {
            update(segtree, 2 * i, depth + 1, total_depth, l, m, pos, val);
        } else {
            update(segtree, 2 * i + 1, depth + 1, total_depth, m + 1, r, pos, val);
        }
        if ((total_depth - depth) % 2 == 0) {
            segtree[i] = segtree[2 * i] ^ segtree[2 * i + 1];
        } else {
            segtree[i] = segtree[2 * i] | segtree[2 * i + 1];
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int depth, m;
    cin >> depth >> m;
    int n = 1 << depth;
    vector<int> segtree(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> segtree[i + n];
    }
    build(segtree, 1, 0, depth);
    for (int i = 0; i < m; i++) {
        int p, b;
        cin >> p >> b;
        update(segtree, 1, 0, depth, 1, n, p, b);
        cout << segtree[1] << endl;
    }

    return 0;
}
