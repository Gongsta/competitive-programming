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

/*
If left has
5 duplicates
+ 1 unique

Right is symmetric. Might be different numbers. But the unique numbers are going to be on the right

k - 2 * duplicates + unique
*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        k = 2 * k;
        int a[2 * n];
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[a[i]]++;
        }
        int num_duplicates = 0;
        set<int> to_use;
        for (auto x : m) {
            if (x.second == 2 && k > 1) {
                to_use.insert(x.first);
                k -= 2;
                num_duplicates++;
            }
        }
        for (auto x : m) {
            if (x.second == 1 && k > 0) {
                to_use.insert(x.first);
                k--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (to_use.count(a[i])) {
                cout << a[i] << " ";
            }
        }
        cout << endl;

        m.clear();
        for (int i = n; i < 2 * n; i++) {
            m[a[i]]++;
        }
        for (auto x : m) {
            if (x.second == 2 && num_duplicates > 0) {
                to_use.insert(x.first);
                num_duplicates--;
            }
        }
        for (int i = n; i < 2 * n; i++) {
            if (to_use.count(a[i])) {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
