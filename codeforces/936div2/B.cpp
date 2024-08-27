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
        ll max_sum = 0;
        int n, k;
        cin >> n >> k;
        ll a[n];
        ll MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll curr_sum = 0;
        ll cum_sum = 0;
        int r = 0;
        for (int r = 0; r < n; r++) {
            curr_sum += a[r];
            if (curr_sum < 0) {
                curr_sum = 0;
            }
            max_sum = max(curr_sum, max_sum);

            cum_sum += a[r];
            cum_sum = (cum_sum + MOD) % MOD;
        }
        ll add = max_sum;
        ll add_sum = 0;
        for (int i = 0; i < k; i++) {
            add_sum += add;
            add_sum %= MOD;
            add *= 2;
            add %= MOD;
        }
        cout << (cum_sum + add_sum) % MOD << endl;
    }

    return 0;
}
