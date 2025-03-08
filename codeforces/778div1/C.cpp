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
        int total = 0;
        priority_queue<int> pq1;
        priority_queue<int> pq2;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
            pq2.push(a[i]);
        }
        pq1.push(total);
        bool works = true;
        while (!pq2.empty()) {
            int x = pq2.top();
            pq2.pop();
            int y = pq1.top();
            pq1.pop();
            if (x > y) {
                works = false;
                break;
            } else if (x == y) {
                continue;
            } else {  // x < pq1.top()
                int y1 = y / 2;
                int y2 = y / 2 + y % 2;
                pq1.push(y1);
                pq1.push(y2);
                pq2.push(x);  // try again next time
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
