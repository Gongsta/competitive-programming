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
    /*
    2 3 4 5
    2 2*3 3*4 4*5

    2 4 4
    2 4 4 4

    5 1 4
    5 5 4 4

    greedily try the smallest number that divides both, i.e. b_i = lcm(a_i-1, a_i)
    - there might be other numbers that work but those numbers will be divisible by b_i

    Thus, the gcd will be greater or equal to the one of b_i
    If we setup b_i+1 = lcm(a_i, a_i+1) for all i, then we can guarantee that gcd(b_i, b_i+1) >= a[i]

    How do you formalize this?? i'm so stupid idk how to do this
    I don't even know how to generate these numbers...
    a_i = gcd(b_i, b_i+1)
    a_i+1 = gcd(b_i+1, b_i+2)
    so b2 divides a1 and a2
    you just greedily try the smallest numbers and see if its possible?

    why does that work? Any bigger number doesn't really contribute to the GCD that we want to compute.
    - Like if we generate bigger numbers, we can create larger GCD, but that defeats the purpose of wanting
    to find a number that divides both with that GCD

    proof:
    Suppose 𝑐 is some valid array which gives us a . So, 𝑐𝑖 should be divisible by 𝑏𝑖 . This means gcd(𝑐𝑖,𝑐𝑖+1)≥gcd(𝑏𝑖,𝑏𝑖+1)
    So, if gcd(𝑏𝑖,𝑏𝑖+1)>𝑎𝑖 for any 𝑖, we should also have gcd(𝑐𝑖,𝑐𝑖+1)>𝑎𝑖 . This implies that 𝑐 is not valid if 𝑏 is not valid.
.

    We can always generate these numbers that divide those numbers, however, we cannot guarantee that gcd(b_i, b_i+1) = a_i




    So how do we get those numbers?

    */
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool works = true;
        int prev = a[0];
        int curr = a[0];
        for (int i = 1; i < n; i++) {
            curr = lcm(a[i - 1], a[i]);
            if (gcd(prev, curr) != a[i - 1]) {
                works = false;
                break;
            }
            prev = curr;
        }

        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
