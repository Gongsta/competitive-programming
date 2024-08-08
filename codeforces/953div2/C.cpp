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
Imagine it as a series of swaps.
For each numbers swapped, you increase by 2* some number.

So odd sums are impossible.

*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }

        ll sum = 0;
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            if (sum + 2 * (a[r] - a[l]) > k) {
                r--;
            } else {
                sum += 2 * (a[r] - a[l]);
                swap(a[r], a[l]);
                // cout << "swapping" << r << l << endl;
                // cout << "sum" << sum << endl;
                r--;
                l++;
            }
        }
        if (sum == k) {
            cout << "Yes" << endl;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;

        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
