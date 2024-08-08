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

Think about binary representation of a number. If adjacent 1s, then you can use -1.
Ex:
7 = 0b111
= 0b100(-1)

13
1101 -> (16 -4 + 1)

11
1101
-10-101

111
-1001


1011 = 11 -> 2^0(1 + 2 + 8)
10100 = 20

11111 2^6 + 2^5 = 2^5(1 + 2) = 2^5(4-1)


2^0 + 2^2 + 2^4
1011101
- 1 + 4 + 8 + 16 + 64

-10001


11 (2^k + 2^{k+1}) = 2^{k+2} - 2^k = 2^k * 2^2 - 2^k = 2^k(2^2 - 1)


But could be longer gaps.
10011

*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        // There has to be a 0 every 2 interval
        int x;
        cin >> x;
        vector<int> ans;
        while (x > 0) {
            // cout << x << " " << ((1 << 1) & x) << endl;
            if ((1 & x) && (1 << 1) & x) {
                // cout << x << endl;
                ans.push_back(-1);
                ans.push_back(0);
                x = (x >> 2) + 1;
            } else {
                ans.push_back(x & 1);
                x = x >> 1;
            }
        }
        cout << ans.size() << endl;
        for (auto c : ans) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
