#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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
/*

0 2 3 4 5

*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int s[n];
        for (int i = 0;i<n;i++) {
            cin >> s[i];
        }
        sort(s, s+n);
        int mex = n;
        for (int i = 0;i<n;i++) {
            if (s[i] != i) {
                mex = i;
                break;
            }
        }
        cout << mex << endl;
        int y;
        cin >> y;
        while (y!= -1 && y != -2) {
            cout << y << endl;
            cin >> y;
        }
    }

    return 0;
}
