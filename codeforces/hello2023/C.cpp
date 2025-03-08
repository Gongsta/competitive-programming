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
#include <vector>
// #include <unordered_map> // NEVER USE THOSE IN CP
// #include <unordered_set> // NEVER USE THOSE IN CP

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

/*
Look at the numbers.

So if the prefix[i] < prefix[m] and i < m, you must change a number j between i and m, i<j<=m. Changing a number before i will not change the relative ordering.
Changing a number after m will also not affect anything.
If """ and i > m, then you must change a number between m and i. Same logic, because before i and after m will not affect the relative sum.

Which numbers do you try? You can try to be greedy and impose a sign flip. You always want to find the number that will cause the greatest swindle,
i.e. abs(val) is the greatest.

Let's look at the first case when i < m. You want to flip an index i<j<=m from positive to negative (to make prefix m more negative). You can't make
prefix[i] more positive, because that also affects prefix[m].

For i > m, you want to flip an index m < j <= i from negative to positive, to increase the prefix sum of prefix[i] until it's greater. Reducing prefix[j]
won't work, because those values affect prefix[i].

*/
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        m--;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int prefix[n];
        prefix[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + a[i];
        }
        priority_queue<int> pq;
        int ans = 0;
        if (a[m] > 0) {
            pq.push(a[m]);
        }

        for (int i = m - 1; i >= 0; i--) {
            while (prefix[i] < prefix[m]) {
                ans++;
                prefix[m] -= 2 * pq.top();
                pq.pop();
            }

            if (a[i] > 0) {
                pq.push(a[i]);
            }
        }

        // reset the prefix at m, since relative ordering after is the same
        if (m == 0) {
            prefix[m] = a[m];
        } else {
            prefix[m] = prefix[m - 1] + a[m];
        }

        priority_queue<int, vector<int>, greater<int>> min_pq;
        int offset = 0;
        for (int i = m + 1; i < n; i++) {
            if (a[i] < 0) {
                min_pq.push(a[i]);
            }
            while (prefix[i] + offset < prefix[m]) {
                ans++;
                offset -= 2 * min_pq.top();
                min_pq.pop();
            }
        }
        cout << ans << endl;
    }

    return 0;
}
