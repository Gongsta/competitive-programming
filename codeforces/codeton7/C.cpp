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

/*
1 2 3 4 5

Idea: Take the n greatest numbers from a, and n smallest numbers b.

After we do this, we check if the remaining numbers are all.
*/

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int a_orig[n];
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++) {
            cin >> a_orig[i];
            a[i] = a_orig[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        bool works = true;
        map<int, vector<int>> ans;
        for (int i = 0; i < x; i++) {
            if (b[i] >= a[n - x + i]) {
                works = false;
                break;
            } else {
                ans[a[n - x + i]].push_back(b[i]);
            }
        }
        for (int i = x; i < n; i++) {
            if (b[i] < a[i - x]) {
                works = false;
                break;
            }
            ans[a[i - x]].push_back(b[i]);
        }
        if (works) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << ans[a_orig[i]].back() << " ";
                ans[a_orig[i]].pop_back();
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
