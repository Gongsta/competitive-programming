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
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int score = 0;
        for (int i = n - 1; i >= 0; i -= 2) {
            if (i == 0) {
                score += a[i];
            } else {
                ll dec = min(k, a[i] - a[i - 1]);
                a[i] -= dec;
                k -= dec;
                score += a[i] - a[i - 1];
            }
        }
        cout << score << endl;
    }

    return 0;
}
