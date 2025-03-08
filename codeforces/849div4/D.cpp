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
        string s;
        cin >> s;
        int alpha[26][n];
        memset(alpha, 0, sizeof(alpha));
        alpha[s[0] - 'a'][0] = 1;

        for (int i = 1; i < s.length(); i++) {
            for (int c = 0; c < 26; c++) {
                char letter = 'a' + c;
                if (s[i] == letter) {
                    alpha[c][i] = alpha[c][i - 1] + 1;
                } else {
                    alpha[c][i] = alpha[c][i - 1];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int left_total = 0;
            int right_total = 0;
            for (int c = 0; c < 26; c++) {
                if (alpha[c][i] > 0) {
                    left_total++;
                }
                if (alpha[c][n - 1] - alpha[c][i] > 0) {
                    right_total++;
                }
            }
            ans = max(ans, left_total + right_total);
        }
        cout << ans << endl;
    }

    return 0;
}
