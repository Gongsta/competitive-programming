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
        int a, b, c;
        cin >> a >> b >> c;
        if (a > c) {
            swap(a, c);
        }
        int g[3];
        g[0] = a;
        g[1] = c / 2;
        g[2] = c / 2 + c % 2;
        sort(g, g + 3);
        b -= g[2] - g[0];
        g[0] = g[2];
        b -= g[2] - g[1];
        g[1] = g[2];
        b = max(b, 0ll);
        int add = 0;
        if (b % 3 != 0) {
            add++;
        }
        cout << g[2] + b / 3 + add << endl;
    }

    return 0;
}
