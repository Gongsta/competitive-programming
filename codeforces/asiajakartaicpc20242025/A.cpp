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

set<char> vow = {'A', 'E', 'I', 'O', 'U'};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int char_cnt[26];
    memset(char_cnt, 0, sizeof(char_cnt));
    for (char x : s) {
        char_cnt[x - 'A']++;
    }

    int N = 'N' - 'A';
    int G = 'G' - 'A';
    int Y = 'Y' - 'A';
    int ans = 0;

    for (int i = 0; i <= min(char_cnt[N], char_cnt[G]); i++) {
        char_cnt[N] -= i;
        char_cnt[G] -= i;

        int nv = 0;
        int nc = i;
        for (int j = 0; j < 26; j++) {
            if (vow.count('A' + j)) {
                nv += char_cnt[j];
            } else if (j != Y) {
                nc += char_cnt[j];
            }
        }

        char_cnt[N] += i;
        char_cnt[G] += i;
        int letters = nv + nc + char_cnt[Y];
        int w = min(nv + char_cnt[Y], min((nc + char_cnt[Y]) / 2, letters / 3));
        ans = max(ans, 3 * w + min(2 * w, i));
    }
    cout << ans << endl;
}
