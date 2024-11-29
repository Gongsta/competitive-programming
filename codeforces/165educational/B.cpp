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
        cin >> s;
        int num_ones = 0;
        int num_zeroes = 0;
        int ans = 0;
        vector<pair<char, int>> v;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                num_zeroes++;
            } else {
                num_ones++;
            }
            if (i == 0) {
                continue;
            }
            if (s[i] == '1' && s[i - 1] == '0') {
                v.push_back({'0', num_zeroes});
                num_zeroes = 0;
            } else if (s[i] == '0' && s[i - 1] == '1') {
                v.push_back({'1', num_ones});
                num_ones = 0;
            }
        }

        if (num_zeroes != 0) {
            v.push_back({'0', num_zeroes});
        } else if (num_ones != 0) {
            v.push_back({'1', num_ones});
        }

        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i].first == '1' && v[i + 1].first == '0') {
                ans += (v[i].second + 1) * v[i + 1].second;

                if (i + 2 < v.size()) {
                    v[i + 2].second += v[i].second;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
