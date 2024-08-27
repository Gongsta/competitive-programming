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
        int n, q;
        cin >> n >> q;
        string val[n];
        for (int i = 0; i < n; i++) {
            cin >> val[i];
        }
        vector<string> portals = {"BG", "BR", "BY", "GR", "GY", "RY"};
        vector<int> prev_portal[6];
        vector<int> next_portal[6];
        for (int p = 0; p < 6; p++) {
            int prev = -1;
            for (int i = 0; i < n; i++) {
                if (val[i] == portals[p]) {
                    prev = i;
                }
                prev_portal[p].push_back(prev);
            }
            int next = -1;
            for (int i = n - 1; i >= 0; i--) {
                if (val[i] == portals[p]) {
                    next = i;
                }
                next_portal[p].push_back(next);
            }
            reverse(next_portal[p].begin(), next_portal[p].end());
        }
        while (q--) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if (y < x) {
                swap(x, y);
            }
            if (val[y].find(val[x][0]) != string::npos || val[y].find(val[x][1]) != string::npos) {
                cout << y - x << endl;
            } else {
                // Find the nearest value
                int min_dist = 1e9;
                for (int p = 0; p < 6; p++) {
                    if (portals[p] == val[y] || portals[p] == val[x]) {
                        continue;
                    }
                    if (prev_portal[p][x] != -1) {
                        min_dist = min(min_dist, y - prev_portal[p][x] + x - prev_portal[p][x]);
                    }
                    if (next_portal[p][x] != -1) {
                        if (next_portal[p][x] < y) {
                            min_dist = y - x;
                        } else {
                            min_dist = min(min_dist, next_portal[p][x] - y + (next_portal[p][x] - x));
                        }
                    }
                }
                if (min_dist == 1e9) {
                    cout << -1 << endl;
                } else {
                    cout << min_dist << endl;
                }
            }
        }
    }

    return 0;
}
