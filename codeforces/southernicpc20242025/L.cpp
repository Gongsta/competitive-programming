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
    int n;
    cin >> n;
    int ans = 0;
    /*
    Consider n is even:
    For the first n/2 planks,
    do 2 for 18 and 1 for 21. That gets you 36 + 21 = 57 Best use

    1 of 21 + 1 of 25 (n/2 planks)
    1 of 25 (remaining n/2 planks)

    Total: 3 * n / 2

    If n is odd:
    n/2 + 1 (2 of 18, and 1 for 21)
    1 of 21 + 1 of 25 (n/2 planks)
    1 of 25 (remaining n/2 planks)
    1 of 25 + 1 of 18 (1)

    total: n/2 + 1 + n/2 + n / 2 + 1

This is the greedy way.
    There is a way to do it more optimally???
    yup, greedy works but there's better
    You need 25 + 25 (n/2 times)
    21 + 21 + 18 (n / 2 types)
    you had n/2 of the 18 left, and each uses 3
    n/6

    ok so odd?
    you have an extra 25, 21, so just n mod 2
    */
    cout << n + (n + 6 - 1) / 6 << endl;

    return 0;
}
