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
        int n, m;
        cin >> n >> m;
        string s[n];
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        int ans = 0;
        // edge case with a single asterix
        if (n != 1) {
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    if (count(s[i].begin(), s[i].end(), '#') > count(s[i + 1].begin(), s[i + 1].end(), '#')) {
                        ans = i;
                        break;
                    }
                } else if (i == n - 1) {
                    if (count(s[i].begin(), s[i].end(), '#') > count(s[i - 1].begin(), s[i - 1].end(), '#')) {
                        ans = i;
                        break;
                    }
                } else {
                    if (count(s[i].begin(), s[i].end(), '#') > count(s[i - 1].begin(), s[i - 1].end(), '#') &&
                        count(s[i].begin(), s[i].end(), '#') > count(s[i + 1].begin(), s[i + 1].end(), '#')) {
                        ans = i;
                        break;
                    }
                }
            }
        }
        int num_asterix = 0;
        int first_asterix = -1;
        for (int j = 0; j < m; j++) {
            if (s[ans][j] == '#') {
                num_asterix++;
                if (first_asterix == -1) {
                    first_asterix = j;
                }
            }
        }
        cout << ans + 1 << " " << first_asterix + num_asterix / 2 + 1 << endl;  // 1 indexed
    }

    return 0;
}
