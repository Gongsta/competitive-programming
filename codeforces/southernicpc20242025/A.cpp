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

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i] / b[i];
    }
    if (total < k) {
        for (int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < n; i++) {
            total -= a[i] / b[i];
            int work = 0;
            if (total < k) {
                work = k - total;
            }
            total += work;
            cout << work << " ";
        }
        cout << endl;
    }

    return 0;
}
