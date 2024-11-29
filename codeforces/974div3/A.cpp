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
        int n,k;
        cin >> n >> k;
        int a[n];
        int curr_gold = 0;
        int ans = 0;
        for (int i=0;i<n;i++) {
            cin >> a[i];
            if (a[i] >= k) {
                curr_gold += a[i];
            }
            if (a[i] == 0 && curr_gold > 0) {
                curr_gold--;
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}