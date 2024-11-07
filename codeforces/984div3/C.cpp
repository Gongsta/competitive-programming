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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

bool is_1100(string& s, int i) {
    if (i + 3 >= s.size()) {
        return false;
    }
    return s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int q;
        cin >> q;
        set<int> ss;
        for (int i = 0; i < s.size(); i++) {
            if (is_1100(s, i)) {
                ss.insert(i);
            }
        }
        int i;
        char v;
        while (q--) {
            cin >> i >> v;
            i--;
            if (s[i] != v) {
                s[i] = v;
                for (int j = max(i - 3, 0ll); j <= i; j++) {
                    if (is_1100(s, j)) {
                        ss.insert(j);
                    } else if (ss.count(j)) {
                        ss.erase(j);
                    }
                }
            }
            if (ss.size() > 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
