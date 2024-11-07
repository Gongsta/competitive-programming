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

int query(int index) {
    cout << "? " << 1 << " " << index << endl;
    int sum;
    cin >> sum;
    return sum;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    while (t--) {
        int k;
        cin >> k;
        int l = 1;
        int r = n;
        int ans = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            int sum = query(mid);
            if (mid - sum >= k) {
                r = mid - 1;
                if (mid - sum == k) {
                    ans = min(ans, mid);
                }
            } else {
                l = mid + 1;
            }
        }
        cout << "! " << ans << endl;
    }
    return 0;
}
