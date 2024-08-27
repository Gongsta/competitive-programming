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
dp[i][remaining_val] = maximum number of messages using numbers using messages up to i, with remaining values

return dp[n][l]
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, l;
        cin >> n >> l;
        ll a[n];
        ll b[n];
        vector<pair<ll, ll>> v;
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        for (int i = 0; i < n; i++) {
            v.push_back({b[i], a[i]});
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for (int start = 0; start < n; start++) {
            ll curr = 0;
            priority_queue<ll> pq;
            for (int end = start; end < n; end++) {
                curr += v[end].second;
                pq.push(v[end].second);
                while (!pq.empty() && curr + v[end].first - v[start].first > l) {
                    ll x = pq.top();
                    pq.pop();
                    curr -= x;
                }
                ans = max(ans, (int)pq.size());
            }
        }
        cout << ans << endl;
    }

    return 0;
}
