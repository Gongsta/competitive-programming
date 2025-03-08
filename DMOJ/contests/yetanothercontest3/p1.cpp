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
Left tries to move until the very end. Right tries to move until the very left until you run into a -1.

If both -1 are pointing to the same, then you, simply need to swap start and end.
If start and end are same, use another one

If both -1 are pointing to different, then it can be start and end anywhere. You can decide the swap arbitrarily.
*/
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<pair<int, int>> swaps;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u;
        if (u == -1) {
            swaps.push_back({-1, -1});
        } else {
            cin >> v;
            swaps.push_back({u, v});
        }
    }
    int l = 0;
    int r = m - 1;
    int start = a;
    int end = b;
    while (l <= r) {
        if (swaps[l].first != -1) {
            if (swaps[l].first == start) {
                start = swaps[l].second;
            } else if (swaps[l].second == start) {
                start = swaps[l].first;
            }
            l++;
        } else if (swaps[r].first != -1) {
            if (swaps[r].first == end) {
                end = swaps[r].second;
            } else if (swaps[r].second == end) {
                end = swaps[r].first;
            }
            r--;
        } else if (l == r) {  // both are -1 and point to the same
            if (start == end) {
                for (int i = 1; i <= n; i++) {
                    if (i != start) {
                        swaps[l].first = i;
                        break;
                    }
                }
                for (int i = 1; i <= n; i++) {
                    if (i != start && i != swaps[l].first) {
                        swaps[l].second = i;
                        break;
                    }
                }
            } else {
                swaps[l].first = start;
                swaps[l].second = end;
            }
            l++;
        } else {  // make it arbitrary, you can do anything
            swaps[l].first = 1;
            swaps[l].second = 2;
        }
    }
    for (int i = 0; i < swaps.size(); i++) {
        cout << swaps[i].first << " " << swaps[i].second << endl;
    }

    return 0;
}
