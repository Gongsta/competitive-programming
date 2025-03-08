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
        int n, m;
        cin >> n >> m;
        cout << "? 1 1" << endl;
        int dist;
        cin >> dist;
        int c = min(1 + dist, m);
        int r = 1;
        if (1 + dist > m) {
            // horizontal line
            cout << "? " << 1 + dist << " " << 1 << endl;
            int y;
            cin >> y;
            cout << "! " << 1 + dist << " " << 1 + y << endl;
        } else if (1 + dist > n) {
            // vertical line down
            cout << "? " << 1 << " " << 1 + dist << endl;
            int y;
            cin >> y;
            cout << "! " << 1 + y << " " << 1 + dist << endl;
        } else {
            // somewhere on the diagonal
            cout << "? " << 1 << " " << 1 + dist << endl;
            int y;
            cin >> y;
            if (1 + y < 1 + dist) {
                cout << "! " << 1 + y << " " << 1 + dist << endl;
            } else {
                cout << "? " << 1 + y << " " << 1 + dist << endl;
                int x;
                cin >> x;
                cout << "! " << 1 + y << " " << 1 + dist - x << endl;
            }
        }
    }

    return 0;
}
