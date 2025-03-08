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

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;
/*

2 scenarios:
1. lots of positive numbers, k is too small
- Have 2 pqs, one that stores negative and one that stores postive. Try to swap to smaller for a negative number. Max of sum

2. k has more than positive numbers.
- Do the same thing, but you get to flip numbers for free.

*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    sort(h, h + n);
    int l = 0;
    int r = n - 1;
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> positive_pq;
    priority_queue<int, vector<int>, greater<int>> negative_pq;
    for (int i = 0; i < k; i++) {
        if (r < 0 || h[r] < 0) {
            break;
        }
        positive_pq.push(h[r]);
        ans += h[r];
        r--;
    }

    while (l <= r && h[l] < 0) {
        negative_pq.push(h[l]);
        l++;
    }
    int free = k - positive_pq.size();
    while (free >= 2) {
        if (negative_pq.empty()) {
            break;
        }
        int x = negative_pq.top();
        negative_pq.pop();
        positive_pq.push(-x);
        ans += -x;
        free -= 2;
    }

    int curr_sum = ans;
    while (!negative_pq.empty() && positive_pq.size() >= (2 - free)) {
        int x = negative_pq.top();
        negative_pq.pop();
        curr_sum += -x;
        int y = positive_pq.top();
        positive_pq.pop();
        curr_sum -= y;
        if (free == 0) {
            int z = positive_pq.top();
            positive_pq.pop();
            curr_sum -= z;
        } else {
            free--;
        }
        positive_pq.push(-x);
        ans = max(ans, curr_sum);
    }
    cout << ans << endl;

    return 0;
}
