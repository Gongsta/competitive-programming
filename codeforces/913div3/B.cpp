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
        deque<pair<char, int>> lower;
        deque<pair<char, int>> upper;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'B') {
                if (!upper.empty()) {
                    upper.pop_back();
                }
            } else if (c == 'b') {
                if (!lower.empty()) {
                    lower.pop_back();
                }
            } else if ('a' <= c && c <= 'z') {
                lower.push_back({c, i});
            } else {
                upper.push_back({c, i});
            }
        }
        while (!lower.empty() || !upper.empty()) {
            if (lower.empty()) {
                cout << upper.front().first;
                upper.pop_front();
            } else if (upper.empty()) {
                cout << lower.front().first;
                lower.pop_front();
            } else {
                if (upper.front().second < lower.front().second) {
                    cout << upper.front().first;
                    upper.pop_front();
                } else {
                    cout << lower.front().first;
                    lower.pop_front();
                }
            }
        }
        cout << endl;
    }

    return 0;
}
