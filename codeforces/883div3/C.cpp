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
        int n, m, h;
        cin >> n >> m >> h;
        int t[n][m];
        vector<pair<pair<int, int>, int>> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> t[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            sort(t[i], t[i] + m);
            int penalty = 0;
            int time = 0;
            int score = 0;
            for (int j = 0; j < m; j++) {
                time += t[i][j];
                if (time <= h) {
                    score++;
                    penalty += time;
                } else {
                    break;
                }
            }
            if (i == 0) {
                v.push_back({{score, -penalty}, 1});
            } else {
                v.push_back({{score, -penalty}, 0});
            }
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            if (v[i].second == 1) {
                cout << i + 1 << endl;
            }
        }
    }

    return 0;
}
