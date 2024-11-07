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
        int n;
        cin >> n;
        string s;
        bool reached_right_end = false;
        while (s.size() != n) {
            if (reached_right_end) {
                cout << "? 0" << s << endl;
            } else {
                cout << "? " << s << "0" << endl;
            }
            int val;
            cin >> val;
            if (val == 1) {
                if (reached_right_end) {
                    s = "0" + s;
                } else {
                    s = s + "0";
                }
            } else {
                if (s.empty()) {
                    s = s + "1";
                } else if (reached_right_end) {
                    s = "1" + s;
                } else {
                    cout << "? " << s << "1" << endl;
                    int val2;
                    cin >> val2;
                    if (val2 == 1) {
                        s = s + "1";
                    } else {
                        reached_right_end = true;
                    }
                }
            }
        }
        cout << "! " << s << endl;
    }

    return 0;
}
