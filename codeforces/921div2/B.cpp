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

vector<int> get_divisors(int x) {
    vector<int> divisors;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divisors.push_back(i);
            if (i != x / i) {
                divisors.push_back(x / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    reverse(divisors.begin(), divisors.end());
    return divisors;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*
    For 9 2
    its actually 3 + 6
    and not 4 + 5, because that gcd is 0
    10 3
    it's 4,2,4 NO, it's actually 2 + 2 + 6

    So the way you think about it is
    Find the largest k such that

    k (n-1) + ?k = x
    so (n- 1 + ? ) k = x
    so k is a divisor of x

    Go through all the divisors, and see if (n-1)k < x
    Find the largest divisor k such that (n-1)k < x
    */
    int t;
    cin >> t;
    while (t--) {
        int x;
        int n;
        cin >> x >> n;
        if (x % n == 0) {
            cout << x / n << endl;
        } else {
            vector<int> divisors = get_divisors(x);
            for (auto div : divisors) {  // always possible with div == 1
                if ((n - 1) * div < x) {
                    cout << div << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
