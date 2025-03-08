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

int fact(int n) {
    if (n == 1) {
        return n;
    }
    return n * fact(n - 1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        cout << "1 ";
        if (n >= 3) {
            cout << "3 ";
        } else {
            int val = d + 10 * d;
            if (val % 3 == 0) {
                cout << "3 ";
            }
        }
        if (d == 5) {
            cout << "5 ";
        }
        if (d == 7 || n >= 3) {
            cout << "7 ";
        }  // Multiple of 6 digits for the same number works for some reason...?

        if (n >= 9) {
            cout << "9";
        } else {
            int num = fact(n) * d;
            if (num % 9 == 0) {
                cout << "9";
            }
        }
        cout << endl;
    }

    return 0;
}
