#include <algorithm>
#include <bitset>
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
    /*
    Observation: The 2x2 wiping is only useful for cases with rows under 4. Anything more will require 4 wipes of 2x2s, so might as well use the horizontal
    So only 2 cases:
    at most 2 -> clear 2 rows with 1 wipe
    at most 4 -> clear 3-4 rows with 3 wipes

    But how are you confident? Use your BS meter.
    Because h / 2 * 2 = h -> baseline is h
    So you need some rows where only 1 grid is used and that clears 2 columns,

    xxx
    xxxx
    xx
    xx

    So answer + 1 if a_i > 4, else look at numbers below
    */
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= 0) {
                continue;
            }
            ans++;
            if (a[i] <= 2 && i + 1 < n) {
                if (a[i + 1] <= 2) {
                    a[i + 1] = 0;
                } else if (a[i + 1] <= 4) {
                    if (i + 2 < n && a[i + 2] <= 4) {
                        a[i + 1] = 0;
                        a[i + 2] = min(a[i + 2], 2);
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
