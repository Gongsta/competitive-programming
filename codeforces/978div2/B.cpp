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
        int n, x;
        cin >> n >> x;
        ll a[n];
        ll cum_sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cum_sum += a[i];
        }
        sort(a, a + n);
        cout << max(a[n - 1], (ll)ceil((double)cum_sum / (double)x)) << endl;
    }

    return 0;
}
