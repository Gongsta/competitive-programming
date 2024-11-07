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
        int n;
        cin >> n;
        int k = 2;
        int r;

        set<int> branches;
        branches.insert(1);

        vector<int> p(n, 0);
        while (k < n) {  // at most n-2 queries
            cout << "? " << 1 << " " << k << endl;
            cin >> r;
            if (r == 0) {
                branches.erase(1);
                branches.insert(k);
                p[k] = 1;
                k++;
                break;
            } else {
                branches.insert(k);
                p[k] = 0;
                k++;
            }
        }

        while (k < n) {
            int curr_branch = *branches.begin();
            cout << "? " << curr_branch << " " << k << endl;
            cin >> r;

            branches.erase(curr_branch);
            if (r == 0) {
                branches.insert(k);
                p[k] = curr_branch;
                k++;
            }
        }

        cout << "! ";
        for (int i = 1; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
