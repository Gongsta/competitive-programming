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
        int x = 0;
        int y = 0;
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        bool works = false;

        if (x == a && y == b) {
            works = true;
        }
        for (int i = 0; i < 100; i++) {
            for (auto c : s) {
                if (c == 'N') {
                    y++;
                } else if (c == 'S') {
                    y--;
                } else if (c == 'E') {
                    x++;
                } else {
                    x--;
                }
                if (x == a && y == b) {
                    works = true;
                }
            }
        }
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
