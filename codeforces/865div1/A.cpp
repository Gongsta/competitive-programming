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

/*
Observation:
- we can apply -1 0 1 or 1 0 -1 -> 1 0 0 1 -> 1 0 0 0 -1

So the net sum remains the same.

So just check distances. if a[i] > a[j] && (j - i) % 2 == 1, then it doesn't work

but even that is not true is it??

So if n % 2 == 1, always works

Else, need to do some checking. Like it definitely works for some even n's:

consider:
4 100 2 102
4-80 100 100 102 -> works..

*/
#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n % 2 == 1) {
            cout << "YES" << endl;
        } else {
            int even_extra = 0;
            int odd_extra = 0;
            for (int i = n - 2; i >= 0; i--) {
                if (a[i] > a[i + 1]) {
                    if (i % 2 == 0) {
                        even_extra += a[i] - a[i + 1];
                    } else {
                        odd_extra += a[i] - a[i + 1];
                    }
                    a[i] = a[i + 1];
                }
            }
            a[n - 1] += odd_extra;
            for (int i = 0; i < n; i += 2) {
                even_extra -= a[i + 1] - a[i];
                a[i] = a[i + 1];
            }
            a[n - 2] += even_extra;
            if (a[n - 2] > a[n - 1]) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}
