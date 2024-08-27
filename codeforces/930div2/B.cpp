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
        int n;
        cin >> n;
        string a[2];
        cin >> a[0];
        cin >> a[1];
        int row = 0;
        string ans;
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                ans += a[row][i];
                if (row == 0) {
                    ans += a[row + 1][i];
                }
            } else {
                ans += a[row][i];
                if (row == 0) {  // consider looking down
                    if (a[row + 1][i] < a[row][i + 1]) {
                        row++;
                        ans += a[row][i];
                    }
                }
            }
        }
        int last_correct_idx = 0;
        bool works = true;
        for (int i = 0; i < n; i++) {
            if (a[0][i] == ans[i] && works) {
                last_correct_idx = i;
            } else {
                works = false;
            }
        }
        int last_incorrect_idx = -1;
        for (int i = 0; i < n; i++) {
            if (a[1][i] != ans[i + 1]) {
                last_incorrect_idx = i;
            }
        }

        cout << ans << endl;
        cout << last_correct_idx - last_incorrect_idx << endl;
    }

    return 0;
}
