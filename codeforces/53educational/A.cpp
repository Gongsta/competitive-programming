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
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> ss;
    for (auto c : s) {
        ss.insert(c);
    }
    if (ss.size() < 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                cout << s[i - 1] << s[i] << endl;
                break;
            }
        }
    }

    return 0;
}
