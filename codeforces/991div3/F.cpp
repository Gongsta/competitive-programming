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

const int MAX_N = 200005;

int a[MAX_N];
int d[MAX_N];
int p_min[2 * MAX_N];
int p_max[2 * MAX_N];
int tree_gcd[2 * MAX_N];

int N, N_diff;

int query_min(int l, int r) {
    int res = INT_MAX;
    l += N;
    r += N + 1;  // Make r inclusive
    while (l < r) {
        if (l % 2 == 1) {
            res = min(res, p_min[l++]);
        }
        if (r % 2 == 1) {
            res = min(res, p_min[--r]);
        }
        l /= 2;
        r /= 2;
    }
    return res;
}

int query_max(int l, int r) {
    int res = INT_MIN;
    l += N;
    r += N + 1;  // Make r inclusive
    while (l < r) {
        if (l % 2 == 1) {
            res = max(res, p_max[l++]);
        }
        if (r % 2 == 1) {
            res = max(res, p_max[--r]);
        }
        l /= 2;
        r /= 2;
    }
    return res;
}

int query_gcd(int l, int r) {
    int res = 0;
    l += N_diff;
    r += N_diff + 1;
    while (l < r) {
        if (l % 2 == 1) {
            res = gcd(res, tree_gcd[l++]);
        }
        if (r % 2 == 1) {
            res = gcd(res, tree_gcd[--r]);
        }
        l /= 2;
        r /= 2;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        N = n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < N; ++i) {
            p_min[N + i] = a[i];
            p_max[N + i] = a[i];
        }
        for (int i = N - 1; i > 0; --i) {
            p_min[i] = min(p_min[2 * i], p_min[2 * i + 1]);
            p_max[i] = max(p_max[2 * i], p_max[2 * i + 1]);
        }

        if (n == 1) {
            for (int i = 0; i < q; ++i) {
                int l, r;
                cin >> l >> r;
                cout << "0\n";
            }
            continue;
        }

        int n_diff = n - 1;
        N_diff = n_diff;
        for (int i = 0; i < n_diff; ++i) {
            d[i] = a[i + 1] - a[i];
        }

        for (int i = 0; i < N_diff; ++i) {
            tree_gcd[N_diff + i] = abs(d[i]);
        }
        for (int i = N_diff - 1; i > 0; --i) {
            tree_gcd[i] = gcd(tree_gcd[2 * i], tree_gcd[2 * i + 1]);
        }

        // Process queries
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (l == r) {
                cout << "0 ";
                continue;
            }
            int min_val = query_min(l, r);
            int max_val = query_max(l, r);
            if (min_val == max_val) {
                cout << "0";
                continue;
            }
            int gcd_val = query_gcd(l, r - 1);
            cout << gcd_val << " ";
        }
        cout << endl;
    }
    return 0;
}
