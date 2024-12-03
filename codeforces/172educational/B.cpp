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
        int n;
        cin >> n;
        int c[n];
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            m[c[i]]++;
        }
        map<int, vector<int>> cnt;
        for (auto& x : m) {
            cnt[x.second].push_back(x.first);
        }

        bool alice = true;
        int ans = 0;
        for (auto& x : cnt) {
            if (x.first == 1) {
                for (auto& v : x.second) {
                    if (alice) {
                        ans += 2;
                    }
                    alice = !alice;
                }
            } else {
                for (auto& v : x.second) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
