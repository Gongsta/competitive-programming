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
        int a[n];
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]]++;
        }
        int good = 0;

        vector<int> points;

        for (auto x : m) {
            x.second -= x.second % 2;
            for (int i = 0; i < x.second; i++) {
                points.push_back(x.first);
            }
        }

        if (points.size() < 8) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            int p1 = points[0];
            int p2 = points[2];
            int p3 = points[points.size() - 4];
            int p4 = points.back();
            if ((p3 - p1) * (p4 - p2) > (p4 - p1) * (p3 - p2)) {
                swap(p1, p2);
            }

            cout << p1 << " " << p2 << " ";
            cout << p1 << " " << p3 << " ";
            cout << p4 << " " << p2 << " ";
            cout << p4 << " " << p3;
            cout << endl;
        }
    }

    return 0;
}
