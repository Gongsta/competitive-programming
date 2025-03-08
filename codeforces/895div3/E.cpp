#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
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

/*
prefix xors of ones
prefix xors of zeros

But really, you only need two values?

Yea, so you store a prefix xor for both.

and then precompute the xor for 1
and xor for 0

Then, lets say all a subarray is flipped from l^r.
Your answer for xor1 is first, remove all the values from the subarray [l,r] of 1s.
Then, xor1 will add the values of the 0s from the subarray [l,r]

You need to keep track of when things are flipped.

*/

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

int pref(vector<int>& prefix, int l, int r) {
    if (l == 0) {
        return prefix[r];
    }
    return prefix[r] ^ prefix[l - 1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string s;
        cin >> s;
        // Build the prefix;
        vector<int> prefix0(n, 0);
        vector<int> prefix1(n, 0);
        if (s[0] == '0') {
            prefix0[0] = a[0];
        } else {
            prefix1[0] = a[0];
        }

        // build the prefix;
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                prefix0[i] = prefix0[i - 1] ^ a[i];
                prefix1[i] = prefix1[i - 1];
            } else {
                prefix0[i] = prefix0[i - 1];
                prefix1[i] = prefix1[i - 1] ^ a[i];
            }
        }

        int xor0 = prefix0[n - 1];
        int xor1 = prefix1[n - 1];

        int q;
        cin >> q;
        while (q--) {
            int tp;
            cin >> tp;
            if (tp == 1) {
                int l, r;
                cin >> l >> r;
                l--;
                r--;
                xor0 ^= pref(prefix0, l, r);
                xor0 ^= pref(prefix1, l, r);
                xor1 ^= pref(prefix1, l, r);
                xor1 ^= pref(prefix0, l, r);
            } else {
                int bit;
                cin >> bit;
                if (bit == 0) {
                    cout << xor0 << " ";
                } else {
                    cout << xor1 << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
