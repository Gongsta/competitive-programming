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

int mex(int a, int b) {
    set<int> s{a, b};
    if (!s.count(0)) {
        return 0;
    }
    if (!s.count(1)) {
        return 1;
    }
    return 2;
}
int mex(int a, int b, int c) {
    set<int> s{a, b, c};
    if (!s.count(0)) {
        return 0;
    }
    if (!s.count(1)) {
        return 1;
    }
    if (!s.count(2)) {
        return 2;
    }
    return 3;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*
    Base case:
    if even,
    0 1 0 1 ...

    0 1 0 1 0 1 0 1

    if odd,
    0 1 2
    0 1 0 1 2 ...

    Now, we need to add a friend edge.
    1 friend with 0 is no problem, and vice versa

    2 friend with anyone is no problem!

    However, friend with itself is problem. 0 friend with a_j == 0 is a problem
    1 friends with 1 is a problem.
    but it's fine, just make one of them 2.

    If it's a 0 that is friends with 0, make one of them 1.




    0 1 0 1 0 1 2
    */

    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        x--;
        y--;
        int a[n];
        for (int i = 0; i < n; i++) {
            a[i] = i % 2;
        }
        if (n % 2 == 1) {
            a[n - 1] = 2;
        }
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < n; i++) {
                if (i == x) {
                    a[i] = mex(a[(i - 1 + n) % n], a[(i + 1) % n], a[y]);
                } else if (i == y) {
                    a[i] = mex(a[(i - 1 + n) % n], a[(i + 1) % n], a[x]);
                } else {
                    a[i] = mex(a[(i - 1 + n) % n], a[(i + 1) % n]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
