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
        int a, b, r;
        cin >> a >> b >> r;
        if (a < b) {
            swap(a, b);
        }
        int x = 0;
        bool first_swap = true;
        int ans = 0;
        for (int bit = 62ll; bit >= 0ll; bit--) {
            int bit_num = 1ll << bit;
            int a_bit = bit_num & a;
            int b_bit = bit_num & b;
            if ((a_bit ^ b_bit) && a_bit) {  // different signs, a is postive
                if (first_swap) {
                    first_swap = false;
                } else {
                    if (x + bit_num <= r) {
                        x += bit_num;
                    }
                }
            }
        }
        cout << abs((a ^ x) - (b ^ x)) << endl;
    }

    return 0;
}
