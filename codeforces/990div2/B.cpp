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
        // Replace least with most
        map<char, int> m;
        for (auto c : s) {
            m[c]++;
        }
        map<int, char> m_rev;
        for (auto x : m) {
            m_rev[x.second] = x.first;
        }
        for (auto x : m) {
            // hack for duplicates
            if (m_rev[x.second] != x.first && !m_rev.count(x.second + 1)) {
                m_rev[x.second + 1] = x.first;
            }
        }
        bool swapped_first = false;
        bool swapped_last = false;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == (*m_rev.begin()).second && !swapped_first) {
                s[i] = (*m_rev.rbegin()).second;
                swapped_first = true;
            } else if (c == (*m_rev.rbegin()).second && !swapped_last) {
                s[i] = (*m_rev.rbegin()).second;
                swapped_last = true;
            }
        }
        cout << s << endl;
    }

    return 0;
}
