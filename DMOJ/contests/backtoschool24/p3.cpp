#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;

using namespace std;

struct Node {
    int sum;
    int max_val;
};

const int MAXN = 1 << 18;
Node t[4 * MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {  // Leaf node
        t[v].sum = a[tl];
        t[v].max_val = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);                                     // Build the left child
        build(a, v * 2 + 1, tm + 1, tr);                             // Build the right child
        t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;                  // Sum of the segment
        t[v].max_val = max(t[v * 2].max_val, t[v * 2 + 1].max_val);  // Maximum value in the segment
    }
}

struct QueryResult {
    int sum;
    int max_val;
};

QueryResult query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return {0, INT_MIN};
    }
    if (l == tl && r == tr) {
        return {t[v].sum, t[v].max_val};
    }
    int tm = (tl + tr) / 2;

    QueryResult left = query(v * 2, tl, tm, l, min(r, tm));
    QueryResult right = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);

    int total_sum = left.sum + right.sum;
    int total_max = max(left.max_val, right.max_val);

    return {total_sum, total_max};
}

int custom_formula(int v, int tl, int tr, int l1, int r1, int l2, int r2) {
    QueryResult first = query(v, tl, tr, l1, r1);

    QueryResult second = query(v, tl, tr, l2, r2);

    int a_minus_b = first.sum;
    int c_minus_d = second.sum;
    int max_diff = first.max_val - second.max_val;

    return (a_minus_b * a_minus_b) + (c_minus_d * c_minus_d) + (max_diff * max_diff);
}


// /*
// Idea: use a segment tree? Range tree?
// */

// const int MAXN = (1 << 18) + 1;
// int n;
// int t[4 * MAXN];

// int sum(int v, int tl, int tr, int l, int r) {
//     if (l > r) {
//         return 0;
//     }
//     if (l == tl && r == tr) {
//         return t[v];
//     }
//     int tm = (tl + tr) / 2;
//     return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
// }

// void build(vector<ll>& a, int v, int tl, int tr) {
//     if (tl == tr) {
//         t[v] = a[tl];
//     } else {
//         int tm = (tl + tr) / 2;
//         build(a, v * 2, tl, tm);
//         build(a, v * 2 + 1, tm + 1, tr);
//         t[v] = t[v * 2] + t[v * 2 + 1];
//     }
// }

// int get_first(int v, int tl, int tr, int l, int r, int x) {
//     if (tl > r || tr < l) {
//         return -1;
//     }
//     if (t[v] <= x) {
//         return -1;
//     }

//     if (tl == tr) {
//         return tl;
//     }

//     int tm = tl + (tr - tl) / 2;
//     int left = get_first(2 * v, tl, tm, l, r, x);
//     if (left != -1) {
//         return left;
//     }
//     return get_first(2 * v + 1, tm + 1, tr, l, r, x);
// }

// void update(int v, int tl, int tr, int pos, int new_val) {
//     if (tl == tr) {
//         t[v] = new_val;
//     } else {
//         int tm = (tl + tr) / 2;
//         if (pos <= tm) {
//             update(v * 2, tl, tm, pos, new_val);
//         } else {
//             update(v * 2 + 1, tm + 1, tr, pos, new_val);
//         }
//         t[v] = t[v * 2] + t[v * 2 + 1];
//     }
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_set<ll> nums;
    ll n;
    cin >> n;

    vector<ll> a(n, 0);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i + 1];
        nums.insert(a[i + 1]);
    }
    ll missing_num = 1;
    for (int i = 1; i < n; i++) {
        if (!nums.count(i)) {
            missing_num = i;
            break;
        }
    }
    a[0] = missing_num;
    build(a, 1, 0, n - 1);

    vector<ll> ans;
    ans.push_back(custom_formula(1, 0, n - 1, 0, n - 1));
    for (int i = 0; i < n - 1; i++) {
        // Before and after
        update(1, 0, n - 1, i, a[i + 1]);
        update(1, 0, n - 1, i + 1, a[i]);
        swap(a[i], a[i + 1]);
        ans.push_back(sum(1, 0, n - 1, 0, n - 1));
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
