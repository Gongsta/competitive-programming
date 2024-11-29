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
        /*
        Observation, if a_i - a_{i+1} >= 2, impossible
        ex: 3 1 2 -> Impossible to sort it
        1 3 4 2

        Doesn't work for all cases. The real observation is a_i - i >= 2 means impossible.
        Else, always possible given that it is a permutation.
        */
        int n;
        cin >> n;
        int p[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        bool works = true;
        for (int i = 1; i <= n; i++) {
            if (abs(p[i] - i) >= 2) {
                works = false;
                break;
            }
        }

        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
