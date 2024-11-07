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

int total_inversions(vector<int> v) {
    int total = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j]) {
                total++;
            }
        }
    }
    return total;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, vector<pair<int, int>>> m;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            m[a + b].push_back({a, b});
        }
        for (auto &x : m) {
            for (auto &v : x.second) {
                cout << v.first << " " << v.second << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
