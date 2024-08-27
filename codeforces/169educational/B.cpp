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
        int l, r;
        cin >> l >> r;
        int L, R;
        cin >> L >> R;
        if (r < L || R < l) {
            cout << 1 << endl;
        } else {
            cout << min(max(l, L) - min(l, L), 1) + min(max(R, r) - min(r, R), 1) + min(r, R) - max(l, L) << endl;
        }
    }

    return 0;
}
