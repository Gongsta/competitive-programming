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
        int n, k, pb, ps;
        cin >> n >> k >> pb >> ps;
        int p[n + 1];
        int a[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int max_bodya_score = 0;
        int max_sasha_score = 0;
        set<int> visited;
        int curr_sum = 0;
        while (!visited.count(pb)) {
            visited.insert(pb);
            curr_sum += a[pb];
            int n_visited = visited.size();
            int remaining = k - n_visited;
            max_bodya_score = max(max_bodya_score, curr_sum + a[pb] * remaining);
            pb = p[pb];
            if (remaining == 0) {
                break;
            }
        }

        visited.clear();
        curr_sum = 0;
        while (!visited.count(ps)) {
            visited.insert(ps);
            curr_sum += a[ps];
            int n_visited = visited.size();
            int remaining = k - n_visited;
            max_sasha_score = max(max_sasha_score, curr_sum + a[ps] * remaining);
            ps = p[ps];
            if (remaining == 0) {
                break;
            }
        }
        // cout << max_bodya_score << " " << max_sasha_score << endl;

        // can move at most 10 times
        if (max_bodya_score > max_sasha_score) {
            cout << "Bodya" << endl;
        } else if (max_sasha_score > max_bodya_score) {
            cout << "Sasha" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }

    return 0;
}
