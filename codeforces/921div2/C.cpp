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

/*
aabbcccabab

aabbc
ccab
ab
*/

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k, m;
        cin >> n >> k >> m;
        string s;
        cin >> s;
        set<char> char_tracker;
        int total = 0;
        string ans;
        for (auto c : s) {
            if (c <= 'a' + k - 1) {
                char_tracker.insert(c);
            }

            if (char_tracker.size() == k) {
                ans += c;  // last character that was seen that made it fill
                total++;
                char_tracker.clear();
            }
        }
        if (total >= n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
            cout << ans;
            for (int i = 0; i < k; i++) {
                if (!char_tracker.count('a' + i)) {
                    for (int j = ans.size(); j < n; j++) {
                        cout << (char)('a' + i);
                    }
                    cout << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
