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
    /*
    You will greet them if their end point lies between your start and end point
    - not quite, need both start and end to be between, else consider  0-3 and 1-4
    - they will never cross even though end point 3 is between 1 and 4

    Iterate based on start points
    Query the number of points that end before the end point

    */

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int b[n];
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cin >> b[i];
            v.push_back({b[i], a[i]});
        }
        sort(v.begin(), v.end());
        set<int> s;
        int total = 0;
        for (int i = 0; i < n; i++) {
            auto it = s.upper_bound(v[i].second);
            total += i - distance(s.begin(), it);
            s.insert(v[i].second);
        }
        cout << total << endl;
    }

    return 0;
}
