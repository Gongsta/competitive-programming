#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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
        map<char, int> counter;
        for (auto c : s) {
            counter[c]++;
        }
        int n = s.size();

        char ans[n];
        int l = 0;
        int r = n - 1;
        for (auto x : counter) {
            for (int i = 0; i < x.second / 2; i++) {
                ans[l + i] = x.first;
                ans[r - i] = x.first;
            }
            l += x.second / 2;
            r -= x.second / 2;

            if (x.second % 2 == 1) {  // odd, look at how many remainings and do final computation
                vector<char> remaining;
                for (auto y : counter) {
                    if (y.first <= x.first) {
                        continue;
                    }
                    remaining.push_back(y.first);
                }

                if (remaining.size() == 1) {  // special case
                    char y = remaining[0];
                    for (int i = 0; i < counter[y] / 2 + (counter[y] % 2); i++) {
                        ans[l] = y;
                        l++;
                    }
                    ans[l] = x.first;
                    l++;
                    for (int i = 0; i < counter[y] / 2; i++) {
                        ans[l] = y;
                        l++;
                    }
                } else {
                    ans[r] = x.first;
                    r--;
                    for (char y : remaining) {
                        for (int i = 0; i < counter[y]; i++) {
                            ans[l] = y;
                            l++;
                        }
                    }
                }

                break;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}
