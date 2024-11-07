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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n == 1) {
            cout << 1 << endl;
            cout << 1 << endl;
        } else {
            if (k % 2 == 0) {
                cout << 3 << endl;
                cout << 1 << " " << k << " " << k + 1 << endl;
            } else {
                if (1 == k || k == n) {
                    cout << -1 << endl;
                } else {
                    cout << 3 << endl;
                    cout << 1 << " " << k - 1 << " " << k + 2 << endl;
                }
            }
        }
    }

    return 0;
}
