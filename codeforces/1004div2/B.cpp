#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
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
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& x : m) {
            if (x.second >= 4) {
                m[x.first + 1] += x.second - (2 + (x.second % 2));
                x.second = 2 + (x.second % 2);
            }
        }
        for (auto x : m) {
            if (x.second % 2 == 1) {
                pq.push(x.first);
            }
        }
        bool works = true;
        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            bool found = false;
            while (m[x] > 1 && !pq.empty() && x < pq.top()) {
                if (x + 1 == pq.top()) {
                    found = true;
                    pq.pop();
                    break;
                } else {
                    // m[x]--;
                    x++;
                    // m[x]++;
                }
            }
            if (!found) {
                works = false;
                break;
            } else {
                m[x + 1]++;
                while (m[x + 1] > 2) {
                    m[x + 2] += 2;
                    m[x + 1] -= 2;
                    x++;
                }
            }
        }
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
