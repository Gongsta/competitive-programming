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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int num = a[0];
        int ans = n;
        int consec = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == num) {
                consec++;
            } else {
                ans = min(ans, consec);
                consec = 0;
            }
        }
        ans = min(ans, consec);

        if (ans == n) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}
