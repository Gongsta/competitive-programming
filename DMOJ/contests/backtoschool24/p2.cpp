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
    ll n, m;
    cin >> n >> m;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll b[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    set<pair<pair<ll, ll>, ll>> s;
    vector<ll> diff(m, 0);
    ll curr_i = 0;
    for (int i = 0; i < n; i++) {
        diff[curr_i] += a[i];
        if (curr_i + b[i] >= m) {
            diff[0] += a[i];
            diff[(curr_i + b[i]) % m] -= a[i];
        } else {
            diff[curr_i + b[i]] -= a[i];
        }
        curr_i += b[i];
        curr_i %= m;
    }
    vector<ll> cum_sum(m, 0);
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            cum_sum[i] = diff[i];
        } else {
            cum_sum[i] = cum_sum[i - 1] + diff[i];
        }
        cout << cum_sum[i] << " ";
    }
    cout << endl;

    return 0;
}
