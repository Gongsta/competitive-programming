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
p...s not possible

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
        bool works = true;
        bool seen_p = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'p') {
                seen_p = true;
            } else if (s[i] == 's' && seen_p) {
                works = false;
            }
        }
        int first_s = 0;
        int first_p = 0;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == 's' && first_s == 0) {
                first_s = i;
            }
            if (s[i] == 'p') {
                first_p = i;
            }
        }
        if (first_s != 0 && first_p != 0) {
            works = false;
        }

        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
