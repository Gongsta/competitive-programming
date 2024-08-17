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
        int h, n;
        cin >> h >> n;
        ll a[n];
        ll c[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        priority_queue<pair<ll, ll>> pq;
        // priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({-1, i});
        }
        /*
        Start from smallest intervals. That doesn't work as well. We essentially need to query a database with
        the largest value that is smaller than the current value...

        Like I have the sieve of erastones idea, but it doesn't actually work too. YOu need like the sums to cumulate.

        Why can't we just brute force all the intervals?
        Like worst case is O(n^2) if there's a bunch of 1s, this is a big problem
        Solution is just to insert pairs, ahh, makes sense. Until you get to the answer.

        it's just brute-forcing, but know how to implement it.
        */
        ll ans = 1;
        ll total = 0;
        while (true) {
            auto x = pq.top();
            pq.pop();
            total += a[x.second];
            pq.push({x.first - c[x.second], x.second});
            ans = -x.first;
            if (total >= h) {
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
