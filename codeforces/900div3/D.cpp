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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int l[k];
        int r[k];
        for (int i = 0; i < k; i++) {
            cin >> l[i];
            l[i]--;
        }
        for (int i = 0; i < k; i++) {
            cin >> r[i];
            r[i]--;
        }
        int q;
        cin >> q;
        int x[q];
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < q; i++) {
            cin >> x[i];
            x[i]--;
            cnt[x[i]]++;
        }
        string ans;
        for (int i = 0; i < k; i++) {
            int cum_cnt = 0;
            string sub_s = s.substr(l[i], r[i] - l[i] + 1);

            for (int j = (l[i] + r[i]) / 2 + 1; j <= r[i]; j++) {
                int dist = j - (l[i] + r[i]) / 2;
                cnt[(l[i] + r[i]) / 2 + ((l[i] + r[i]) % 2) - dist] += cnt[j];
            }
            for (int j = l[i]; j <= (l[i] + r[i]) / 2; j++) {
                cum_cnt += cnt[j];
                if (cum_cnt % 2 == 1) {
                    swap(sub_s[j - l[i]], sub_s[r[i] - j]);
                }
            }
            ans += sub_s;
        }
        cout << ans << endl;
    }

    return 0;
}
