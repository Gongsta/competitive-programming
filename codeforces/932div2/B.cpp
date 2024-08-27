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
        int a[n];
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        int mex = 0;
        for (int i = 0; i <= n; i++) {
            if (!s.count(i)) {
                mex = i;
                break;
            }
        }
        set<int> mex_size;
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (mex_size.size() == mex) {
                break;
            }
            r = i;
            if (a[i] < mex) {
                mex_size.insert(a[i]);
            }
        }
        mex_size.clear();
        for (int i=r+1;i<n;i++) {
            if (a[i] < mex) {
                mex_size.insert(a[i]);
            }
        }
        if (mex_size.size() != mex) {
            cout << -1 << endl;
        } else {
            cout << 2 << endl;
            cout << 1 << " " << r + 1 << endl;
            cout << r+2 << " " << n << endl;

        }
    }

    return 0;
}
