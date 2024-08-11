#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
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

typedef long long ll;

using namespace std;

/*
You always want to add, unless it's a 1 or 0, in which case ALWAYS multiply.
There are n-1 gaps, just find the gap with the two smallest numbers.
If the two smallest numbers is == 0, answer is 0.
If it's 1, the answer is the sum excluding this number.
Else, add this number.

Then, it's just computing it.

You only need to miniimze a, b doesn't matter.

if it has 0 or more zeros, return 0.
if it has 1 zero, check the case of length 3, else its also zero.

Else,
*/

int value(string& s, int i) {
    int val = (s[i] - '0') * 10 + (s[i + 1] - '0');
    return val;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zeros++;
            }
        }

        if (n == 2) {
            cout << value(s, 0) << endl;
        } else if (zeros >= 2) {
            cout << 0 << endl;
        } else if (zeros == 1 && n > 3) {
            cout << 0 << endl;
        } else {
            int cumsum[n];
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    cumsum[i] = s[i] - '0';
                } else {
                    if (s[i] - '0' == 1) {
                        cumsum[i] = cumsum[i - 1];
                    } else {
                        cumsum[i] = cumsum[i - 1] + (s[i] - '0');
                    }
                }
            }
            int ans = 99 + (n - 2) * 9;
            for (int i = 0; i < n - 1; i++) {
                int before = 1;
                int after = 1;
                if (i > 0) {
                    before = cumsum[i - 1];
                }
                if (i < n - 2) {
                    after = (cumsum[n - 1] - cumsum[i + 1]);
                }
                int local_ans = value(s, i);
                if (local_ans * before > local_ans + before) {
                    local_ans += before;
                } else {
                    local_ans *= before;
                }

                after = max(after, 1);
                if (local_ans * after > local_ans + after) {
                    local_ans += after;
                } else {
                    local_ans *= after;
                }
                ans = min(ans, local_ans);
            }

            cout << ans << endl;
        }
    }

    return 0;
}
