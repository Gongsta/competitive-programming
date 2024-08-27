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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int w;
        cin >> w;
        ll a[w];
        for (int i = 0; i < w; i++) {
            cin >> a[i];
        }
        sort(a, a + w, greater<ll>());

        ll val[n][m];
        memset(val, 0, sizeof(val));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                val[i][j] = (min(i, n - k) - max(i - k, -1)) * (min(j, m - k) - max(j - k, -1));
            }
        }

        priority_queue<ll> pq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pq.push(val[i][j]);
                // cout << val[i][j] << " ";
            }
            // cout << endl;
        }
        ll ans = 0;
        for (int i = 0; i < w; i++) {
            // cout << a[i] << " ";
            ll multi = pq.top();
            pq.pop();
            ans += multi * a[i];
        }  // Sort grid by number of times each cell contributes. Greedily use the first "w" best cells
        cout << ans << endl;
    }

    return 0;
}
