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
2 4 3 8 10  1

*/

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        if (n % x == 0) {
            cout << x << " ";
            int next = x;
            for (int i = 2; i < n; i++) {
                if (i == next) {
                    bool found = false;
                    int j = 2;
                    while (j * i < n) {
                        if (n % (j * i) == 0) {
                            found = true;
                            cout << j * i;
                            next = j * i;
                            break;
                        }
                        j++;
                    }
                    if (!found) {
                        cout << n;
                    }
                } else {
                    cout << i;
                }
                cout << " ";
            }
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
