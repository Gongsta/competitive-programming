#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
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
        int x[3];
        cin >> x[0] >> x[1] >> x[2];
        sort(x, x + 3);
        int ans = 3 * x[2];
        for (int i = x[0]; i <= x[2]; i++) {
            int local_ans = abs(x[0] - i) + abs(x[1] - i) + abs(x[2] - i);
            ans = min(ans, local_ans);
        }
        cout << ans << endl;
    }

    return 0;
}
