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

bool is_increasing(int num) {  // this is non-decreasing
    int last = 10;
    while (num > 0) {
        if (num % 10 > last) {
            return false;
        }
        last = num % 10;
        num /= 10;
    }
    return true;
}

int first_digit(int num) {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

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
        int last = a[n - 1];
        bool works = true;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] > last) {
                if (is_increasing(a[i]) && ((a[i] % 10) <= last)) {
                    last = first_digit(a[i]);
                } else {
                    works = false;
                    break;
                }
            } else {
                last = a[i];
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
