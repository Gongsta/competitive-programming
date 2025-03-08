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
        We do 2 passes:
        1st pass: Store the set of characters that can be decreased for "free"
        2nd pass: Decrease the characters until we are not allowed to
        */
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        set<char> ss;
        for (int i = 0; i < s.length(); i++) {
            while (!ss.count(s[i]) && k > 0) {
                ss.insert(s[i]);
                if (s[i] == 'a') {
                    break;
                }
                s[i]--;
                k--;
            }
        }

        for (int i = 0; i < s.length(); i++) {
            while (s[i] > 'a' && ss.count(s[i])) {
                s[i]--;
            }
        }
        for (auto c : s) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
