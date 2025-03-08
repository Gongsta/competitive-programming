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

/*
First character:
- If 0, only player 1 can win
- If 1, everyone but 1 can win

But answer is always 1 for the first one.

For the second one,
10 vs. 01 (12 or 32). Who stays matters


Second character -> depends on previous character, but the previous character it's not like
an elimination thingy.


*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int consec_zeros = 0;
        int consec_ones = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                consec_ones = 0;
                consec_zeros++;
                cout << i + 2 - consec_zeros << " ";
            } else {
                consec_zeros = 0;
                consec_ones++;
                cout << i + 2 - consec_ones << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
