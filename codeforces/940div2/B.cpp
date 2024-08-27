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
        vector<int> ans;
        ll b = 0;
        for (int i = 0; i < 30; i++) {
            if (b + (1 << i) <= k) {
                b += 1 << i;
            }
        }
        if (n == 1) {
            ans.push_back(k);
        } else {
            ans.push_back(k - b);
            while (ans.size() < n) {
                ans.push_back(b);
                b = 0;
            }
        }

        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
