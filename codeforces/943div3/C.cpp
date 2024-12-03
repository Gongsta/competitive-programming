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
        int n;
        cin >> n;
        int a[n];
        int x[n];
        int total = 0;
        for (int i = 1; i < n; i++) {
            cin >> x[i];
            total += x[i];
        }
        total++;

        int curr_sum = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                a[i] = total;
            } else {
                a[i] = x[i] + a[i - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}