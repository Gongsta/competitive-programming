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

bool query(int num) {
    cout << "? 1 " << num << endl;
    int ans;
    cin >> ans;
    if (ans == num) {
        return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int l = 2;
        int r = 999;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (query(mid)) {
                l = mid + 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }
        cout << "! " << ans << endl;
    }

    return 0;
}
