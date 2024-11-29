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
        int d1, d2, d3;
        cin >> d1;
        /*
        So the logic is the same, but it's just a little annoying from an implementation perspective.
        */
        int c = min(1 + d1, m);
        pair<int, int> top_right = {
            d1 - c + 2, c};
        int r = min(top_right.first + (top_right.second - 1), n);
        pair<int, int> bottom_left = {r, d1 - r + 2};
        cout << "? " << top_right.first << " " << top_right.second << endl;
        cin >> d2;
        cout << "? " << bottom_left.first << " " << bottom_left.second << endl;
        cin >> d3;
        cout << "? " << top_right.first + d2 / 2 << " " << top_right.second - d2 / 2 << endl;
        int d4;
        cin >> d4;
        if (d4 == 0) {
            cout << "! " << top_right.first + d2 / 2 << " " << top_right.second - d2 / 2 << endl;
        } else {
            cout << "! " << bottom_left.first - d3 / 2 << " " << bottom_left.second + d3 / 2 << endl;
        }
    }
    return 0;
}
