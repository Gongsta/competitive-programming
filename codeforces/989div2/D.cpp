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
#include <vector>
// #include <unordered_map> // NEVER USE THOSE IN CP
// #include <unordered_set> // NEVER USE THOSE IN CP

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        set<int> twos;
        set<int> ones;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                ones.insert(i);
            } else if (a[i] == 2) {
                twos.insert(i);
            }
        }
        int target = n;
        vector<pair<int, int>> swaps;

        int n_twos = twos.size();
        while (target > n - n_twos) {
            if (!twos.count(target)) {  // need to do swaps
                int pos = *twos.begin();
                twos.erase(*twos.begin());
                if (a[target] == 1) {  // one_pos = target
                    swaps.push_back({pos, target});
                    swap(a[pos], a[target]);
                } else {  // it's a 0
                    swaps.push_back({*ones.begin(), target});
                    swap(a[target], a[*ones.begin()]);
                    swaps.push_back({target, pos});
                    swap(a[target], a[pos]);
                }
                ones.erase(*ones.begin());
                ones.insert(pos);
            } else {
                twos.erase(target);
            }
            target--;
        }
        int l = 1;
        int r = target;
        while (l < r) {
            if (a[l] > a[r]) {
                swaps.push_back({l, r});
                swap(a[l], a[r]);
                l++;
                r--;
            } else if (a[l] < a[r]) {
                l++;
                r--;
            } else if (a[l] == 1) {  // 1, 1
                r--;
            } else {  // 0, 0
                l++;
            }
        }
        cout << swaps.size() << endl;
        for (auto& swap : swaps) {
            cout << swap.first << " " << swap.second << endl;
        }
    }

    return 0;
}
