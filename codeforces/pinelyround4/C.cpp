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
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> ans;
        for (int b = 29; b >= 0; b--) {
            ll curr_b = 1 << b;
            ans.push_back(curr_b);
            for (int i = 0; i < n; i++) {
                a[i] = abs(a[i] - curr_b);
            }
        }
        bool has_zero = false;
        bool has_one = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                has_zero = true;
            } else {
                has_one = true;
            }
        }
        if (has_zero && has_one) {
            cout << -1 << endl;
        } else if (has_zero) {
            cout << ans.size() << endl;
            for (auto c : ans) {
                cout << c << " ";
            }
            cout << endl;
        } else {
            cout << ans.size() + 1 << endl;
            for (auto c : ans) {
                cout << c << " ";
            }
            cout << 1 << endl;
        }
    }

    return 0;
}
