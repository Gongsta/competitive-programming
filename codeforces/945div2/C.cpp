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
        int p[n];
        int max_idx = 0;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            if (p[i] == n) {
                max_idx = i;
            }
        }
        vector<int> ans(n, 0);
        int largest = n / 2;
        set<int> s;
        int start = 0;
        if (max_idx % 2 == 0) {
            start = 1;
        }

        // Fill in small number indices, all these numbers < n
        for (int i = start; i < n; i += 2) {  // Fill the small numbers
            ans[i] = n - p[i];
            if (ans[i] <= n / 2) {
                s.insert(ans[i]);
            }
        }
        int smallest = 1;
        for (int i = start; i < n; i += 2) {  // Replace large numbers used with smaller ones.
            if (ans[i] > n / 2) {
                while (s.count(smallest)) {
                    smallest++;
                }
                ans[i] = smallest;
                s.insert(ans[i]);
            }
        }

        for (int i = (start + 1) % 2; i < n; i += 2) {  // Fill the small numbers
            ans[i] = (n + 1) - p[i];
            if (ans[i] > n / 2) {
                s.insert(ans[i]);
            }
        }
        smallest = n / 2;
        for (int i = (start + 1) % 2; i < n; i += 2) {  // Fill the small numbers
            if (ans[i] <= n / 2) {
                while (s.count(smallest)) {
                    smallest++;
                }
                ans[i] = smallest;
                s.insert(ans[i]);
            }
        }
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
