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
        /*
        Impossible when odd number of abs(1). Else, should always be possible. Consider the scenarios:
        1 1 -> 1 -1
        -1 -1 -> -1 1
        1 0 -1 -> dont do anything
        1 0 1 -> 1 and 0 1 - > 1 -1
        */
        int sum = 0;
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (abs(sum) % 2 == 1) {
            cout << -1 << endl;
        } else {
            vector<int> pos;
            for (int i = 0; i < n; i++) {
                if (a[i] != 0) {
                    pos.push_back(i);
                }
            }
            if (pos.empty()) {
                cout << 1 << endl;
                cout << 1 << " " << n << endl;
            } else {
                vector<pair<int, int>> ans;
                if (pos[0] != 0) {
                    ans.push_back({0, pos[0] - 1});
                }

                for (int i = 0; i < pos.size(); i += 2) {
                    int dist = pos[i + 1] - pos[i];
                    if (a[pos[i]] == a[pos[i + 1]]) {  // same sign
                        if (dist % 2 == 1) {
                            ans.push_back({pos[i], pos[i + 1]});  // those two will cancel out
                        } else {
                            ans.push_back({pos[i], pos[i]});
                            ans.push_back({pos[i] + 1, pos[i + 1]});
                        }
                    } else {
                        if (dist % 2 == 0) {
                            ans.push_back({pos[i], pos[i + 1]});  // those two will cancel out
                        } else {
                            ans.push_back({pos[i], pos[i]});
                            ans.push_back({pos[i] + 1, pos[i + 1]});
                        }
                    }

                    if (pos[i + 1] != n - 1) {  // segment of 0s
                        if (i + 2 < pos.size()) {
                            if (pos[i + 1] + 1 <= pos[i + 2] - 1) {
                                ans.push_back({pos[i + 1] + 1, pos[i + 2] - 1});
                            }
                        } else {  // last element, with remaining zeros
                            ans.push_back({pos[i + 1] + 1, n - 1});
                        }
                    }
                }
                cout << ans.size() << endl;
                for (auto v : ans) {
                    cout << v.first + 1 << " " << v.second + 1 << endl;
                }
            }
        }
    }

    return 0;
}
