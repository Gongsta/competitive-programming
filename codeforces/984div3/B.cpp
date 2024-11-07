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

#define int long long  // Because i'm so done with integer overflow mistakes

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> btp;
        for (int i = 0; i < k; i++) {
            int b, c;
            cin >> b >> c;
            btp[b] += c;
        }
        vector<int> p;
        for (auto x : btp) {
            p.push_back(x.second);
        }
        sort(p.begin(), p.end(), greater<int>());
        int remaining = n;
        int ans = 0;
        for (auto x : p) {
            if (remaining == 0) {
                break;
            }

            remaining--;
            ans += x;
        }
        cout << ans << endl;
    }

    return 0;
}
