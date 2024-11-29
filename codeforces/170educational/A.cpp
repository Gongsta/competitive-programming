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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        string t;
        cin >> s >> t;
        if (s.size() > t.size()) {
            swap(s, t);
        }
        int free = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i]) {
                free++;
            } else {
                break;
            }
        }
        if (free > 0) {
            cout << s.size() + 1 + (t.size() - free) << endl;
        } else {
            cout << s.size() + t.size() << endl;
        }
    }

    return 0;
}
