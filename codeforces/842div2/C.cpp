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

    /*
    // Edge conditions: if 1 appears more than once, or any other number appears
    more than twice

    If 1 appears, then two cannot appear twice.
    So greedily start from the smallest number.

    Fill in the numbers that are mandatory like this:

    5 5 1 2 2

    5 ? 1 2 ?
    ? 5 ? ? 2

    at the same time, you can figure out what is the smallest number that you
    can use to fill other numbers using the smallest that hasn't been seen so far>

    3 3 4 4


    */
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int b[n];
        int c[n];
        set<int> used;
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]].push_back(i);
        }
        int curr_b = 1;
        int curr_c = 1;
        set<int> b_used;
        set<int> c_used;
        bool works = true;

        for (auto x : m) {
            if (x.second.size() > 2) {
                works = false;
                break;
            }
            if (x.second.size() >= 1) {
                b[x.second[0]] = x.first;
                b_used.insert(x.first);
            }

            if (x.second.size() == 2) {
                c[x.second[1]] = x.first;
                c_used.insert(x.first);
                while (b_used.count(curr_b)) {
                    curr_b++;
                }
                b[x.second[1]] = curr_b;
                b_used.insert(curr_b);
            }

            while (c_used.count(curr_c)) {
                curr_c++;
            }
            c[x.second[0]] = curr_c;
            c_used.insert(curr_c);
        }
        for (int i = 0; i < n; i++) {
            if (max(b[i], c[i]) != a[i]) {
                works = false;
                break;
            }
        }

        if (works) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << b[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < n; i++) {
                cout << c[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
