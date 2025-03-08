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
        int n, m, q;
        cin >> n >> m >> q;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int b[m];
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        set<int> s;

        bool works = true;
        int l = 0;
        for (int i = 0; i < m; i++) {
            if (s.count(b[i]) || b[i] == a[l]) {
                if (b[i] == a[l]) {
                    s.insert(a[l]);
                    l++;
                }
            } else {
                works = false;
            }
        }
        if (works) {
            cout << "YA" << endl;
        } else {
            cout << "TIDAK" << endl;
        }
    }

    return 0;
}
