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

If two numbers the same doesn't matter. NO, only if both zeros

Always choose the highest number?? What's so hard.
- Actually, if both 1s, it's the tricky part, or both zeros, it's which movie to downgrade.

Then, do some math.

Is rating A = X, rating B = y

Positive + negative = net
- Distribute this net number over to X and Y. That's your answer

Difference



*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a_rating = 0;
        int b_rating = 0;
        int n;
        cin >> n;
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int pos = 0;
        int neg = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                a_rating += a[i];
            } else if (b[i] > a[i]) {
                b_rating += b[i];
            } else {
                if (a[i] == 1) {
                    pos++;
                } else if (a[i] == -1) {
                    neg++;
                }
            }
        }

        if (a_rating < b_rating) {
            swap(a_rating, b_rating);
        }

        int ans = min(a_rating - neg, b_rating + pos);  // Iniial answer

        b_rating += pos;
        if (b_rating > a_rating) {
            int excess_pos = b_rating - a_rating;
            b_rating = a_rating;
            int net = excess_pos - neg;
            if (net > 0) {
                ans = b_rating + net / 2;
            } else {
                ans = b_rating + net / 2 - abs(net) % 2;
            }
        } else {
            // Figure out how to distribute the neg
            if (a_rating - neg >= b_rating) {
                a_rating -= neg;
                ans = b_rating;
            } else {
                int excess_neg = neg - (a_rating - b_rating);
                ans = b_rating - excess_neg / 2 - excess_neg % 2;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
