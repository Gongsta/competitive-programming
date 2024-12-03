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
        int p[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        bool visited[n + 1];
        memset(visited, 0, sizeof(visited));
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                continue;
            }
            int cycle_length = 1;
            visited[i] = true;
            int curr = p[i];
            while (curr != i) {
                cycle_length++;
                visited[curr] = true;
                curr = p[curr];
            }
            ans += (cycle_length - 1) / 2;
        }
        cout << ans << endl;
    }

    return 0;
}
