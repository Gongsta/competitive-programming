#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
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
        int n = s.size();
        int prefix[n][5];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                if (s[i] == (j + 'A')) {
                    if (i == 0) {
                        prefix[i][j] = 1;
                    } else {
                        prefix[i][j] = prefix[i - 1][j] + 1;
                    }
                } else {
                    if (i == 0) {
                        prefix[i][j] = 0;
                    } else {
                        prefix[i][j] = prefix[i - 1][j];
                    }
                }
            }
            // just brute force, O(5n). Use prefixes to compute scores
        }
    }

    return 0;
}
