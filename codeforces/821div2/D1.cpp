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

/*
Both should have the same parity, else won't work.
Then, find all the bits where its different, and those are the ones you need to flip.



*/
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        vector<int> diffs;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                diffs.push_back(i);
            }
        }

        if (diffs.size() % 2 == 1) {
            cout << -1 << endl;
        } else {
            if (diffs.size() == 2 && diffs[1] - diffs[0] == 1) {
                cout << min(x, 2 * y) << endl;
            } else {
                cout << (diffs.size() / 2) * y << endl;
            }
        }
    }

    return 0;
}
