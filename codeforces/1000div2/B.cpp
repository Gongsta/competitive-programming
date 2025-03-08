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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        l--;
        r--;
        priority_queue<int> pq_l;
        priority_queue<int> pq_r;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = l; i <= r; i++) {
            pq_l.push(a[i]);
            pq_r.push(a[i]);
        }
        for (int i = 0; i < l; i++) {
            if (a[i] < pq_l.top()) {
                pq_l.pop();
                pq_l.push(a[i]);
            }
        }

        for (int i = r + 1; i < n; i++) {
            if (a[i] < pq_r.top()) {
                pq_r.pop();
                pq_r.push(a[i]);
            }
        }
        int ans_l = 0;
        int ans_r = 0;
        while (!pq_l.empty()) {
            int x = pq_l.top();
            pq_l.pop();
            ans_l += x;
        }
        while (!pq_r.empty()) {
            int x = pq_r.top();
            pq_r.pop();
            ans_r += x;
        }
        cout << min(ans_l, ans_r) << endl;
    }

    return 0;
}
