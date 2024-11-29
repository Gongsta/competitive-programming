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

// do a graph traversal
int ans[(int)1e5 + 1];
bool visited[(int)1e5 + 1];
vector<int> prefix_tallest(1e5 + 1, 0);
vector<int> suffix_shortest(1e5 + 1, 0);

/*
For suffix shortest,
Actually what we want is the largest index j with a[j] < a[i].

for prefix longest, we want the largest number.
So its actually at most
*/
int dfs(int i, bool is_smaller) {
    if (visited[i]) {
        return ans[i];
    }
    visited[i] = true;
    ans[i] = i;  // Initialize the value, might change after
    if (is_smaller) {
        ans[i] = dfs(prefix_tallest[i], false);
    } else {
        ans[i] = dfs(suffix_shortest[i], true);
    }
    return ans[i];
}

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
        // Greedily check for the shortest, then the tallest
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                prefix_tallest[i] = i;
            } else {
                if (a[i] > a[prefix_tallest[i - 1]]) {
                    prefix_tallest[i] = i;
                } else {
                    prefix_tallest[i] = prefix_tallest[i - 1];
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                suffix_shortest[i] = i;
            } else {
                if (a[i] < a[suffix_shortest[i + 1]]) {
                    suffix_shortest[i] = i;
                } else {
                    suffix_shortest[i] = suffix_shortest[i + 1];
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            dfs(i, false);
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
