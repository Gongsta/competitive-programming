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

/*
Is there a better strategy for bob??

Read editorial: WTF, you can just take the smallest number??
- Because of the way this problem is set up

*/
signed main() {
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
        sort(a, a + n);
        int l = 0;
        int r = n;
        int ans = 0;
        for (int k = 0; k <= n; k++) {
            multiset<int> ms;
            for (int i = 0; i < n; i++) {
                ms.insert(a[i]);
            }

            bool works = true;
            for (int i = 1; i <= k; i++) {
                // Alice tries to take the largest one that can fit
                while (!ms.empty() && *ms.rbegin() > k - i + 1) {  // remove all that don't fit
                    ms.erase(prev(ms.end()));
                }
                if (ms.empty()) {
                    works = false;
                    break;
                }
                ms.erase(prev(ms.end()));  // alice greedily takes the largest number

                // bob adds value to biggest for next stage
                while (!ms.empty() && *ms.rbegin() > k - (i + 1) + 1) {  // alice will pop those anyways
                    ms.erase(prev(ms.end()));
                }
                if (!ms.empty()) {
                    int x = *ms.begin();
                    ms.erase(ms.begin());
                    ms.insert(x + (k - i + 1));
                }
            }

            if (works) {
                ans = k;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
