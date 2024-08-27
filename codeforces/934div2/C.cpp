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

typedef long long ll;

using namespace std;

/*
Store the count of each value.

Alice will always greedily take the smallest value.

if there is a number missing, then that is the MEX. Unless Bob takes a value that is earlier.

Insight: Bob only needs to greedily take the value.

WRONG: Alice, doesn't just greedily take the smallest value. That would be stupid. If Bob takes, and it's going to be
there anyways, then take the values at risk.

So Alice just copies whatever Bob takes in the case of duplicates.

Alice will first take the values that are not duplicate.

ACtually, even for the zero, she will go for the first values

*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]]++;
        }
        int ans = n;  // highest value
        for (int i = 0; i < n; i++) {
            if (!m.count(i)) {
                ans = i;
                break;
            }
        }
        bool used = false;
        for (auto x : m) {
            if (x.second == 1) {
                if (used) {
                    ans = min(ans, x.first);
                    break;
                } else {
                    used = true;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
