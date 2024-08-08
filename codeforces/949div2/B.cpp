#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
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

0 1 2 3 4 5
1 3 3 7 7 7

look at the bitwise representation of n.
For each n-th bit, it gets flipped every 2^n time.

00 01 10 11 100 101 110 111 1000 1001 1010 1011...
01 11 11 111 111 111 111 1111 1111 1011 1011 1111...
01 11 11 111 111 111 1111 1111 1111 1111 ...


10110010
The number is at most 2^k / 2 away.
Notice that that takes the extra bit time to travel.

10011 10100 10101
10111

10100
- 20

10000


11000


*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int ans = n;
        int bit_num = 0;
        for (int i = 0; i < 31; i++) {
            bit_num += 1 << i;
            if ((n & (1 << i)) == 0) {                    // bit that needs to be added
                if ((1 << i > n) && (1 << i) - n <= m) {  // bigger number
                    ans += 1 << i;
                } else if (1 << i < n && ((n - ((n & ~bit_num) - 1) <= m) || ((((n >> i) << i) + (1 << i) - n) <= m))) {  // check left and right side
                    ans += 1 << i;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
