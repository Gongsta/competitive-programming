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
        int n;
        cin >> n;
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int total_less = 0;
        int dist = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                total_less++;
                dist = b[i] - a[i];
            }
        }
        if (total_less > 1) {
            cout << "NO" << endl;
        } else {
            bool works = true;
            for (int i = 0; i < n; i++) {
                if (a[i] >= b[i]) {
                    if (a[i] - dist < b[i]) {
                        works = false;
                        break;
                    }
                }
            }
            if (works) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
