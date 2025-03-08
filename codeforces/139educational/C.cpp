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
    1. Check for diagonals
    2. Check for black on both sides of W
    3. Check that there are no T shaped things
    */

    int t;
    cin >> t;
    while (t--) {
        string s[2];
        int m;
        cin >> m;
        for (int i = 0; i < 2; i++) {
            cin >> s[i];
        }
        bool works = true;
        int cur = -1;
        for (int i = 0; i < m; i++) {
            if (s[0][i] != s[1][i]) {
                cur = i;
                break;
            }
        }

        if (cur == -1) {
            cout << "YES" << endl;
        } else {
            bool works = true;
            int pos = 0;
            if (s[1][cur] == 'B') {
                pos = 1;
            }
            for (int i = cur + 1; i < m; i++) {
                if (s[0][i] == s[1][i]) {
                    pos = pos ^ 1;
                } else if (s[pos][i] == 'W') {
                    works = false;
                    break;
                }
            }
            if (works) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
