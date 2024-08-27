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
        ll n, c;
        cin >> n >> c;
        ll s[n];
        ll even = 0;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            if (s[i] % 2 == 0) {
                even++;
            }
        }
        ll odd = n - even;
        ll total = (c + 1) + c * (c + 1ll) / 2ll;
        for (int i = 0; i < n; i++) {
            total -= s[i] / 2 + 1;
            total -= c + 1 - s[i];
        }
        total += even * (even + 1ll) / 2ll + odd * (odd + 1ll) / 2ll;
        cout << total << endl;
    }

    return 0;
}
