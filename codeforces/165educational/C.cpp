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
        int a[n];
        int total_sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total_sum += a[i];
        }

        priority_queue<pair<int, pair<int, int>>> pq;

        for (int i = 1; i < n; i++) {
            pq.push({abs(a[i] - a[i - 1]), {i - 1, i}});
        }

        for (int i = 0; i < k; i++) {
            if (pq.empty()) {
                break;
            }
            auto x = pq.top();
            pq.pop();

            int j = x.second.second;
            if (a[j] > a[j - 1]) {
                total_sum -= a[j];
                a[j] = a[j - 1];
                total_sum += a[j];
                if (j + 1 < n) {
                    pq.push({abs(a[j] - a[j + 1]), {j, j + 1}});
                }

            } else {
                total_sum -= a[j - 1];
                a[j - 1] = a[j];
                total_sum += a[j - 1];
                if (j - 2 >= 0) {
                    pq.push({abs(a[j - 2] - a[j - 1]), {j - 2, j - 1}});
                }
            }
        }
        cout << total_sum << endl;
    }

    return 0;
}
