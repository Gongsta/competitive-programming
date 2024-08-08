#include <stdio.h>
#include <string.h>

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

/*
How to produce a grid we want?
Criteria for when it cannot be produced?
- difference of 1 achivable, however if different by 2, and want to get to 0, that's notpossible
- Is it really the parity then? Sum over the squares. Should be mod 6 changeable.

The 4 corners modulus 3 cannot change. Everything else can be used.
- Nope, it's not just that. it's the rows and columns.

But how can you say a grid is reachable if the mod3 is the same for row and column?

0110
0000

0200
0220

0110
0010

0020
0100



0120
0210

0000
0000

0111
0222

0210
0120

21
12

00
00


*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        int b[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char num;
                cin >> num;
                a[i][j] = num - '0';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char num;
                cin >> num;
                b[i][j] = num - '0';
            }
        }
        // Check modulus
        bool works = true;
        for (int i = 0; i < n; i++) {
            int row_sum_a = 0;
            int row_sum_b = 0;
            for (int j = 0; j < m; j++) {
                row_sum_a += a[i][j];
                row_sum_b += b[i][j];
            }
            if (row_sum_a % 3 != row_sum_b % 3) {
                works = false;
            }
        }
        for (int j = 0; j < m; j++) {
            int sum_a = 0;
            int sum_b = 0;
            for (int i = 0; i < n; i++) {
                sum_a += a[i][j];
                sum_b += b[i][j];
            }
            if (sum_a % 3 != sum_b % 3) {
                works = false;
            }
        }

        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
