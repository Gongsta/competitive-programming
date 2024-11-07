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

    int n, m, k;
    cin >> n >> m >> k;
    string s[n];
    vector<int> next_b[n];
    vector<int> next_a[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        int last_seen_a = -1;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                last_seen_a = j;
            }
            next_a[i].push_back(last_seen_a);
        }

        int last_seen_b = -1;
        for (int j = m - 1; j >= 0; j--) {
            if (s[i][j] == 'B') {
                last_seen_b = j;
            }
            next_b[i].push_back(last_seen_b);
        }
        reverse(next_b[i].begin(), next_b[i].end());
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                if (next_b[i][j] == -1 || (next_b[i][j] - j > k)) {
                    cout << "Y";
                } else {
                    cout << "N";
                }
            } else if (s[i][j] == 'B') {
                if (next_a[i][j] == -1 || (j - next_a[i][j] > k)) {
                    cout << "Y";
                } else {
                    cout << "N";
                }
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }

    return 0;
}
