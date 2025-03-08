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
    /*
    10 5 10 5 can become 10 10 and 5 5 so you have perfect score. But when you have a[i-1] < a[i], which number
    do you move to the other side?

    Like for : 10 2 6 5
    you could move 2 to the array (the smaller number)

    But actually, change 10 to 4, i.e. 4 2 6 5
     - you end up with 4 6 5, and 2, which is WRONG. But you can do 4 2 and 6 5 which works.

    Also,
    5 4 3 2 10 1
    - You need to move the bigger number to get a perfect score

    1 5 1 4
    2 4 1 5
    2 5 1 4



    If respects
    */
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int INF = 1e9;
        vector<int> b = {-INF};
        vector<int> c = {-INF};

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if ((a[i] <= b.back() && a[i] <= c.back()) ||
                a[i] > b.back() && a[i] > c.back()) {
                if (b.back() < c.back()) {
                    b.push_back(a[i]);
                } else {
                    c.push_back(a[i]);
                }
            } else {
                if (b.back() > c.back()) {
                    b.push_back(a[i]);
                } else {
                    c.push_back(a[i]);
                }
            }
        }
        int ans = 0;
        for (int i = 2; i < b.size(); i++) {
            if (b[i - 1] < b[i]) {
                ans++;
            }
        }
        for (int i = 2; i < c.size(); i++) {
            if (c[i - 1] < c[i]) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
