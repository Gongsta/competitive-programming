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

// Three parts
1. On left side, all + c > a[i] must be removed
2. On right side, all > a[i] + c must be removed (but that's if all left side is removed).

get this count of extras before reach c, and then do a min(use candiate boost + num extras to remove, not use candidate boost)

so we need to decide whether we need to remove everything on the left, or remove on the right. Like it's a tradeoff.

like 1 4 5 5 with c = 2, you only need to remove 1 candidate.

it's also not that simple, and how do you get linear time??
- you can't get a relationship between i-1 and i.

Idea was off
*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        ll a[n];
        ll max_val = 0;
        int max_idx = 0;
        ll prefix[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i == 0) {
                prefix[i] = a[i];
            } else {
                prefix[i] = prefix[i - 1] + a[i];
            }

            if (a[i] > max_val) {
                max_val = a[i];
                max_idx = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == max_val && i == max_idx && ((i == 0) || (i != 0 && a[0] + c < a[i]))) {
                cout << 0 << " ";
            } else {
                ll prefix_sum = 0;
                if (i == 0) {
                    prefix_sum = 0;
                } else {
                    prefix_sum = prefix[i - 1];
                }
                if (prefix_sum + c + a[i] >= max_val) {
                    cout << i << " ";
                } else {
                    cout << i + 1 << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
