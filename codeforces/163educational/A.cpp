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
        if (n % 2 == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n / 2; i++) {
                if (i % 2 == 0) {
                    cout << "AA";
                } else {
                    cout << "BB";
                }
            }
            cout << endl;
        }
    }

    return 0;
}