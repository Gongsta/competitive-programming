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
        ll n, x;
        cin >> n >> x;
        int p[n + 1];
        unordered_map<int, int> m;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            m[p[i]] = i;
        }
        int l = 1;
        int r = n + 1;
        vector<int> swap_with_greater;
        vector<int> swap_with_lower;

        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (m[x] < mid) {  // On the left side, so we want p[mid] > x
                if (p[mid] <= x) {
                    // Find need a value that is greater than x
                    swap_with_greater.push_back(mid);
                }
                r = mid;
            } else {               // On the right side, so we want p[mid] <= x
                if (p[mid] > x) {  // Need a value that is smaller or equal to x
                    swap_with_lower.push_back(mid);
                }
                l = mid;
            }
        }

        vector<pair<int, int>> swaps;
        set<int> used;
        for (int i = 0; i < max(swap_with_greater.size(), swap_with_lower.size()); i++) {
            if (i < swap_with_greater.size() && i < swap_with_lower.size()) {
                swaps.push_back({swap_with_greater[i], swap_with_lower[i]});
                used.insert(p[swap_with_greater[i]]);
                used.insert(p[swap_with_lower[i]]);
            } else if (i < swap_with_greater.size()) {
                bool found = false;
                for (int j = x + 1; j <= n; j++) {
                    if (!used.count(j)) {
                        swaps.push_back({swap_with_greater[i], m[j]});
                        used.insert(j);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                }
            } else {
                for (int j = 1; j <= x; j++) {
                    if (!used.count(j)) {
                        swaps.push_back({swap_with_lower[i], m[j]});
                        used.insert(j);
                        break;
                    }
                }
            }
        }
        cout << swaps.size() << endl;
        if (swaps.size() > 2) {
            while (true) {
                continue;
            }
        }
        for (auto x : swaps) {
            cout << x.first << " " << x.second << endl;
        }
    }

    return 0;
}
