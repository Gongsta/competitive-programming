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
    /*
    8 7 6 5 4 3 2 1

    For a sequence that is non-decreasing in [a,b,c,d ,...], any number <= (a+b)/2 will keep it increasing.
    For a decreasing sequence in [b,a], any number >= b will flip it well.

    */
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int x = 1e9;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < a[i + 1]) {
                x = min(x, (a[i + 1] + a[i]) / 2);
            }
        }

        for (int i = 0; i < n; i++) {
            a[i] = abs(a[i] - x);
        }

        bool works = true;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                works = false;
                break;
            }
        }

        if (works) {
            cout << x << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
