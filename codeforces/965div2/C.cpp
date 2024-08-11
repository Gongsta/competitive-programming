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
Can just go over the array and compute the median on the fly.
(p + 1) / 2

Median excluding p:
if p > median(n-1):
    num = median(n-1)
else:
    num = median(n-1) + 1

See if the number can be increased

There can be duplicates.

oohh i get it, after you increase the numbers, it's no longer sorted...



*/
int median(int n) {
    return (n + 1) / 2 - 1;  // 0-indexed
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        ll a[n];
        int b[n];
        pair<ll, int> sorted_a[n];
        pair<ll, int> mod1[n];
        pair<ll, int> mod2[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sorted_a[i].first = a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            sorted_a[i].second = b[i];
        }
        sort(sorted_a, sorted_a + n);

        for (int i = 0; i < n; i++) {
            mod1[i] = sorted_a[i];
            mod2[i] = sorted_a[i];
        }

        // Do magic to greedily apply operation

        int m = median(n - 1);
        for (int i = m; i >= 0; i--) {
            if (mod1[i].second == 1) {
                mod1[i].first = min(mod1[i].first + k, mod1[m + 1].first);
                break;
            }
        }
        m = median(n - 1) + 1;
        for (int i = m; i >= 0; i--) {
            if (mod2[i].second == 1) {
                mod2[i].first = min(mod2[i].first + k, mod2[m + 1].first);
                break;
            }
        }
        sort(mod1, mod1 + n);
        sort(mod2, mod2 + n);
        for (int i=0;i<n;i++) {
            cout << mod1[i].first << " ";
        }
        cout << endl;

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int med = 0;
            if (i > median(n - 1)) {
                med = median(n - 1);
            } else {
                med = median(n - 1) + 1;
            }
            ans = max(ans, sorted_a[i].first + sorted_a[med].first);
            if (sorted_a[i].second == 1) {
                ans = max(ans, sorted_a[i].first + sorted_a[med].first + k);
            }

            if (i > median(n - 1)) {
                ans = max(ans, sorted_a[i].first + mod1[med].first);
            } else {
                ans = max(ans, sorted_a[i].first + mod2[med].first);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
