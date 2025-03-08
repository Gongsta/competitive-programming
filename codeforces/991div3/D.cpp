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
        string s;
        cin >> s;
        vector<int> v;
        string ans;
        int n = s.size();
        for (int i = 0; i < min(n, 9ll); i++) {
            v.push_back(s[i]);
        }
        for (int i = 0; i < n; i++) {
            int best_i = 0;
            for (int j = 0; j < v.size(); j++) {
                if (v[j] - j > (v[best_i] - best_i)) {
                    best_i = j;
                }
            }
            ans += (v[best_i] - best_i);
            v.erase(v.begin() + best_i);
            if (i + 9 < n) {
                v.push_back(s[i + 9]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
