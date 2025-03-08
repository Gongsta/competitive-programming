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

    int T;
    cin >> T;
    while (T--) {
        string s[2];
        cin >> s[0] >> s[1];
        int t, q;
        cin >> t >> q;
        int num_diff = 0;
        for (int i = 0; i < s[0].size(); i++) {
            if (s[0][i] != s[1][i]) {
                num_diff++;
            }
        }

        queue<int> blocked;

        for (int i = 0; i < q; i++) {
            int type;
            cin >> type;
            if (!blocked.empty() && blocked.front() == i) {
                blocked.pop();
                num_diff++;
            }

            if (type == 1) {
                int pos;
                cin >> pos;
                pos--;
                if (s[0][pos] != s[1][pos]) {
                    num_diff--;
                    blocked.push(i + t);
                }
            } else if (type == 2) {
                int a, pos_a, b, pos_b;
                cin >> a >> pos_a >> b >> pos_b;
                a--;
                b--;
                pos_a--;
                pos_b--;
                if (s[a][pos_a] != s[1 - a][pos_a]) {
                    num_diff--;
                }
                if (s[b][pos_b] != s[1 - b][pos_b]) {
                    num_diff--;
                }
                swap(s[a][pos_a], s[b][pos_b]);
                if (s[a][pos_a] != s[1 - a][pos_a]) {
                    num_diff++;
                }
                if (s[b][pos_b] != s[1 - b][pos_b]) {
                    num_diff++;
                }

            } else {
                if (num_diff == 0) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        }
    }

    return 0;
}
